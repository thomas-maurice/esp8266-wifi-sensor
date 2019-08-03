#include <Wire.h>
#include <SSD1306Wire.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <FS.h>
#include "font.h"

// Sensor configuration
#define DHTPIN D7     // Change this to change the pin on which the DHT is plugged
#define DHTTYPE DHT11 // Change this to change the type of DHT

#define SSID "default ssid"                     // Default SSID if none is provided
#define PSK "default password"                  // Default password if none is provided
#define DEFAULT_REPORT_URL "http://someurl.com" // Default report URL if none is provided
#define DEVICE_NAME "default device name"       // Default device name if none is provided
#define CACHE_TIME String("86400")              // Cache time to avoid getting the statics at every call, don't remove this as it drastically improves performance

// LED definition
#define LED D4 // LED pin, always D4 on NodeMCU 1.0 boards
bool ledOn = false;

// Display definition
SSD1306Wire display(0x3c, D3, D5);

// DHT Sensor definition
DHT dht(DHTPIN, DHTTYPE);

// Webserver yay
ESP8266WebServer server(80);

// History size (for some reason probably tied to the JSON lib, don't go over 60)
// or that will lead to super strange behaviours memory wise, no idea why
const int HISTORY_SIZE = 60;
// Period is how long the main loop will sleep, in ms
const int PERIOD = 100;
// Sample rate is how every PERIOD do we sample and send a datapoint
const long SAMPLE_RATE = 10 * 60; // Every minute ish
// tick keeps track of the period for the sample rate
long tick = 0;

// Keep track of the last temp and humidity sampled
float last_h = 0;
float last_t = 0;

// TODO(tmaurice): Check if reading it from flash each time is going to kill the flash
// and if not do it to save some bytes.
// Stores the reporting endpoint
String endpoint;
// Stores the device name
String deviceName;

// Historical data for the graphs
float tempHistory[HISTORY_SIZE] = {};
float humidHistory[HISTORY_SIZE] = {};
// Index of the latest metric, since we are in a rolling tape mode
int metricIdx = 0;

// Resets the chip (effectively a soft reboot)
void (*softReset)(void) = 0;

// Setup function, initializes everything
void setup()
{
    Serial.begin(9600);
    // Wait for the serial port to be ready
    while (!Serial)
        ;
    Serial.println();
    Serial.println();

    // LED setup
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH); // Sets the LED to OFF for some reason
    ledOn = false;

    Serial.println("History size: " + String(HISTORY_SIZE));
    Serial.println("Sample rate: " + String(SAMPLE_RATE));
    Serial.println("Period: " + String(PERIOD));

    // Starts the file system
    SPIFFS.begin();

    // Read configuration files
    String ssid = readFile(F("/ssid"), 128);
    if (ssid == "")
    {
        ssid = SSID;
        Serial.println("Using SSID " + ssid + " from firmware");
    }
    else
    {
        Serial.println("Using SSID " + ssid + " from config");
    }

    String pw = readFile(F("/pw"), 128);
    if (pw == "")
    {
        pw = PSK;
        Serial.println("Using pw " + pw + " from firmware");
    }
    else
    {
        Serial.println("Using pw " + pw + " from config");
    }

    endpoint = readFile(F("/endpoint"), 128);
    if (endpoint == "")
    {
        endpoint = DEFAULT_REPORT_URL;
        Serial.println("Using endpoint " + endpoint + " from firmware");
    }
    else
    {
        Serial.println("Using endpoint " + endpoint + " from config");
    }

    deviceName = readFile(F("/name"), 128);
    if (deviceName == "")
    {
        deviceName = DEVICE_NAME;
        Serial.println("Using device name " + deviceName + " from firmware");
    }
    else
    {
        Serial.println("Using device name " + deviceName + " from config");
    }

    // Disable everything to start clean
    WiFi.setAutoConnect(false);
    WiFi.setAutoReconnect(true);
    WiFi.disconnect();

    // Initialising the UI will init the display too.
    display.init();

    display.flipScreenVertically();
    display.setFont(Cousine_Regular_10);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    dht.begin();

    display.clear();
    display.drawStringMaxWidth(40, 30, 128, "Welcome.");
    display.display();

    delay(1500);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pw);

    uint8_t i = 0;

    while (WiFi.status() != WL_CONNECTED)
    {
        display.clear();
        display.drawStringMaxWidth(10, 0, 128, "Connecting to WiFi");
        display.drawStringMaxWidth(10, 15, 128, getWiFiStatus());
        display.drawStringMaxWidth(0, 41, 128, ssid);
        display.drawProgressBar(14, 30, 100, 10, i);
        display.display();
        i = (i + 2) % 100;
        delay(5);
    }
    display.clear();

    // Setting up mDNS
    // TODO(tmaurice): Make this configurable
    if (MDNS.begin("esp8266"))
    {
        display.drawStringMaxWidth(0, 0, 128, "mDNS responder started");
    }
    else
    {
        display.drawStringMaxWidth(0, 0, 128, "Error setting up mDNS responder");
    }

    display.display();
    delay(500);

    // Setting up the web server
    server.on("/", serverHandleRoot);
    server.on("/chart.css", serverHandleChartCSS);
    server.on("/chart.js", serverHandleChartJS);
    server.on("/bootstrap.css", serverHandleBootstrapCSS);
    server.on("/bootstrap.js", serverHandleBootstrapJS);
    server.on("/jquery.js", serverHandleJQueryJS);
    server.on("/notify.js", serverHandleNotifyJS);
    server.on("/infos.json", serverHandleDeviceInfo);
    server.on("/metrics.json", serverHandleMetrics);
    server.on("/metrics", serverHandleMetricsPrometheus);
    server.on("/config", serverHandleConfig);
    server.on("/update_config", HTTP_POST, serverHandleConfigUpdate);
    // TODO(tmaurice): Make these two HTTP POSTs for better semantics
    server.on("/reboot", serverHandleReboot);
    server.on("/toggle_led", serverHandleToggleLed);
    server.begin();
}

String readFile(String fname, int maxSize)
{
    File file = SPIFFS.open(fname, "r");
    if (!file)
    {
        Serial.println("Failed to open file " + fname + " for reading");
        return "";
    }
    String result("");
    while (file.available() && maxSize > 0)
    {
        result += char(file.read());
        maxSize--;
    }
    file.close();
    return result;
}

int writeFile(String fname, String data)
{
    File file = SPIFFS.open(fname, "w");

    if (!file)
    {
        Serial.println("There was an error opening " + fname + " for writing");
        file.close();
        return -1;
    }
    if (!file.print(data))
    {
        Serial.println("File write failed on " + fname);
        file.close();
        return -1;
    }
    file.close();
    return 0;
}

bool sendMetrics()
{
    setLedOn();
    StaticJsonDocument<512> doc;
    WiFiClient client;
    HTTPClient http;
    http.begin(client, endpoint);

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    doc["mac"] = stringMac();
    doc["temperature"] = t;
    doc["humidity"] = h;
    doc["name"] = deviceName;

    String result;
    serializeJson(doc, result);

    Serial.println(result);

    int httpCode = http.POST(result);

    if (httpCode > 0)
    {
        if (httpCode != HTTP_CODE_OK)
        {
            Serial.printf("An error occured :( HTTP %d\n", httpCode);
            String payload = http.getString();
            Serial.println(payload);
        }
    }
    else
    {
        Serial.printf("HTTP POST failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
    setLedOff();
    return true;
}

void serverHandleRoot()
{
    File file = SPIFFS.open("/index.html", "r");
    server.streamFile(file, "text/html");
    file.close();
}

void serverHandleChartCSS()
{
    File file = SPIFFS.open("/chart.css", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/css");
    file.close();
}

void serverHandleChartJS()
{
    File file = SPIFFS.open("/chart.js", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/javascript");
    file.close();
}

void serverHandleBootstrapCSS()
{
    File file = SPIFFS.open("/bootstrap.css", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/css");
    file.close();
}

void serverHandleBootstrapJS()
{
    File file = SPIFFS.open("/bootstrap.js", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/javascript");
    file.close();
}

void serverHandleJQueryJS()
{
    File file = SPIFFS.open("/jquery.js", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/javascript");
    file.close();
}

void serverHandleNotifyJS()
{
    File file = SPIFFS.open("/notify.js", "r");
    // Cache control so we do not re-download that every time
    server.sendHeader("Cache-control", "max-age=" + CACHE_TIME);
    server.streamFile(file, "text/javascript");
    file.close();
}

void serverHandleDeviceInfo()
{
    StaticJsonDocument<512> infos;
    infos["address"] = stringIP();
    infos["mac"] = stringMac();
    infos["temperature"] = dht.readTemperature();
    infos["humidity"] = dht.readHumidity();
    infos["wifi_status"] = getWiFiStatus();
    infos["led_on"] = ledOn;
    infos["name"] = deviceName;
    String result;
    serializeJson(infos, result);
    server.send(200, "application/json", result);
}

void serverHandleMetrics()
{
    DynamicJsonDocument jsonDoc(4096);
    JsonArray tempArray = jsonDoc.createNestedArray("t");
    JsonArray humidArray = jsonDoc.createNestedArray("h");
    for (int i = 0; i < HISTORY_SIZE; i++)
    {
        tempArray.add(tempHistory[i]);
        humidArray.add(humidHistory[i]);
    }
    jsonDoc["idx"] = metricIdx;
    String result;
    serializeJson(jsonDoc, result);
    server.send(200, "application/json", result);
}

void serverHandleMetricsPrometheus()
{
    String result;
    result += "# HELP temperature Temperature measured by the device\n";
    result += "# TYPE temperature counter\n";
    result += "temperature{device=\"" + stringMac() + "\"} " + dht.readTemperature() + "\n";

    result += "# HELP humidity Temperature measured by the device\n";
    result += "# TYPE humidity counter\n";
    result += "humidity{device=\"" + stringMac() + "\"} " + dht.readHumidity() + "\n";

    server.send(200, "text/plain", result);
}

void serverHandleConfig()
{
    StaticJsonDocument<1024> cfg;
    cfg["ssid"] = readFile("/ssid", 128);
    cfg["pwd"] = readFile("/pw", 128);
    cfg["endpoint"] = readFile("/endpoint", 128);
    cfg["name"] = readFile("/name", 128);
    String result;
    serializeJson(cfg, result);
    server.send(200, "application/json", result);
}

void serverHandleConfigUpdate()
{
    if (!server.hasArg("ssid") || !server.hasArg("password") || !server.hasArg("endpoint") || server.arg("ssid") == NULL || server.arg("password") == NULL || server.arg("endpoint") == NULL)
    {
        server.send(400, "text/plain", "400: Invalid Request");
        return;
    }

    if (writeFile("/ssid", server.arg("ssid")))
    {
        server.send(500, "text/html", "failed to update SSID <a href=\"/\">go back</a>");
    }

    if (writeFile("/pw", server.arg("password")))
    {
        server.send(500, "text/html", "failed to update password <a href=\"/\">go back</a>");
    }

    if (writeFile("/endpoint", server.arg("endpoint")))
    {
        server.send(500, "text/html", "failed to update endpoint <a href=\"/\">go back</a>");
    }

    if (writeFile("/name", server.arg("name")))
    {
        server.send(500, "text/html", "failed to update name <a href=\"/\">go back</a>");
    }

    server.send(200, "text/html", "cool and good my dude <a href=\"/\">go back</a>");
}

void serverHandleReboot()
{
    server.send(200, "application/json", "{\"reboot\":\"ok\"}");
    server.close();
    server.stop();

    display.clear();
    display.drawStringMaxWidth(40, 30, 128, "Rebooting");
    display.display();

    delay(1000);

    softReset();
}

void serverHandleToggleLed()
{
    if (ledOn)
    {
        digitalWrite(LED, HIGH);
        ledOn = false;
    }
    else
    {
        digitalWrite(LED, LOW);
        ledOn = true;
    }

    StaticJsonDocument<128> jsonDoc;
    jsonDoc["led_on"] = ledOn;
    String result;
    serializeJson(jsonDoc, result);
    server.send(200, "application/json", result);
}

void setLedOn()
{
    digitalWrite(LED, LOW);
    ledOn = true;
}

void setLedOff()
{
    digitalWrite(LED, HIGH);
    ledOn = false;
}

String stringMac()
{
    unsigned char mac[6];
    WiFi.macAddress(mac);

    String result;
    for (int i = 0; i < 6; ++i)
    {
        result += String(mac[i], 16);
        if (i < 5)
            result += ':';
    }
    return result;
}

String stringIP()
{
    return WiFi.localIP().toString();
}

// Returns the WiFi status in a more human readable form
String getWiFiStatus()
{
    switch (WiFi.status())
    {
    case WL_CONNECTED:
        return String("connected");
        break;
    case WL_NO_SSID_AVAIL:
        return "unknown SSID";
        break;
    case WL_IDLE_STATUS:
        return "idle";
        break;
    case WL_CONNECT_FAILED:
        return "connection failed";
        break;
    case WL_DISCONNECTED:
        return "disconnected";
        break;
    default:
        return "unknown";
        break;
    }
}

// Main loop
void loop()
{
    server.handleClient();
    display.clear();

    if (tick == 0)
    {
        last_h = dht.readHumidity();
        last_t = dht.readTemperature();

        tempHistory[metricIdx] = last_t;
        humidHistory[metricIdx] = last_h;
        metricIdx = (metricIdx + 1) % HISTORY_SIZE;
        sendMetrics();
    }

    display.drawStringMaxWidth(0, 0, 128, String("Temperature: ") + last_t + "°C");
    display.drawStringMaxWidth(0, 10, 128, String("Humidity:    ") + last_h + "%");
    display.drawStringMaxWidth(0, 20, 128, String("IP: ") + stringIP());

    display.drawHorizontalLine(0, 54, 128);
    display.drawStringMaxWidth(0, 54, 128, "WiFi: " + getWiFiStatus());

    display.display();

    tick = (tick + 1) % SAMPLE_RATE;
    delay(PERIOD);
}
