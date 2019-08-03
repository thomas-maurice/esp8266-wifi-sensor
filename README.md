# ESP8266 WiFi temperature & humidity sensor

This is a sensor I've been working on to play around with the ESP8266
WiFi board. Its main goal is to survey on a regular basis the temperature
and the humidity of the room it's in, and consequently updates a display
and optionally send an HTTP POST request to an endpoint if you want to
centralise that somewhere for later use (influxdb for instance).

Hardware you will need:

* An ESP8266 board (I use a generic NodeMCU v1.0)
* An SSD1306 Oled screen (128x64px)
* A DHT11 sensor
* A 10k resistor
* Either some soldering gear or a breadboard and a bunch of jumper cables

The features are the following:

* Surveys temperature and humidity
* Updates a display
* POSTs to an HTTP endpoint a small JSON payload
* Reconfigurable remotely via a web UI, completely hosted on the
chip's flash
* Auto reconnects to the network
* Exposes a Prometheus compatible endpoint
* Cheap af

It does not though:

* Handle HTTPS, neither for the POST nor the UI, the reason is the ESP8266
is absolutely not powerful enough to handle that properly. If you get a
proper ESP32 board tho, it might just work.
* Authentication to the admin interface.

The following features are planned for when I'm not a lazy fuck (or
someone does a pull request):

* Initial configuration in AP mode, which avoids burning initial creds when
you first flash the chip with the firmware.
* Some authentication
* Sending metrics over MQTT instead/in conjunction with HTTP

# Some pictures
The device itself

![The device itself](https://github.com/thomas-maurice/esp8266-wifi-sensor/raw/master/images/sensor.png)

The UI landing page

![Landing page](https://github.com/thomas-maurice/esp8266-wifi-sensor/raw/master/images/screen1.png)

Some graphs idk

![Some graphs](https://github.com/thomas-maurice/esp8266-wifi-sensor/raw/master/images/screen2.png)

The configuration page

![Configuration page](https://github.com/thomas-maurice/esp8266-wifi-sensor/raw/master/images/screen3.png)

The reboot page

![Reboot page](https://github.com/thomas-maurice/esp8266-wifi-sensor/raw/master/images/screen4.png)

# How do I install it ?
## The circuit
The setup is fairly simple:
* For the LCD screen, connect an SSD1306 128x64 screen to the ESP board
over I2C (SCL on SCL, SDA on SDA)
* For the sensor, get a DHT11, VCC on VCC, GND on GND, the data pin to some
digital input on the controller and a pull up resistor on that pin should do it.

Congratulations the board is done.

## The software
First download PlatformIO somehow (I use it on VSCode but apparently atom
is supported as well if you're into that kind of things). Once that's done
you are going to need a few libraries in order to get the thing working:
* Adafruit Unified Sensor
* Adafruit DHT Library
* ArduinoJSON
* ESP8266_SSD1306

Then edit the WiFi credentials for your network in the `data` directory,
the files you are after are `ssid` and `pw`, you cann also change `name`
that is going to be the device's name.

Once that's done, hit the two followinf buttons, the order does not
matter at all:
* Upload
* Upload Filesystem Image

And voila, the chip should display a bootscreen, connect to your WiFi
and start sending information to the endpoint you configured.

# Hacking the UI
The UI (full disclaimer btw I'm what you can think of as the furthest away
from a frontend person, hence I am truely sorry for the low quality of
everything frontend related there if someone cares enough to replace it
with something less shitty that would be amazing kthxbye) is located in the
`data` directory as well. It contains a simple index.html and a bunch of
statics. You can develop there like you would develop basically any front
app, except you have a hard limit of 4 megabytes on the total size of the
whole folder, because everything that is there is going to be bundled on
the chip.

# The "reporting" protocol
The protocol the chip uses to send data is fairly simple, it is going to
do a POST request on an HTTP endpoint, with a payload following this
structure:
```json
{
    "temperature": 42.0,
    "humidity": 69.0,
    "mac": "42:42:42:42:42:42",
    "name": "A device has no name"
}
```

Which is fairly simple. An exemple of a bridge between this sensor and an
InfluxDB database written in Go is provided in `src/server`. Note that the
endpoint does not support any kind of authentication.

# Pull requests/Issues
Knock yourself out, I'd be happy to read them.

# License
```
        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2019 Thomas Maurice

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.
```