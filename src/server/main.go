package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io/ioutil"
	"time"

	influx "github.com/influxdata/influxdb1-client/v2"
	"github.com/sirupsen/logrus"

	"github.com/gin-gonic/gin"
)

type report struct {
	MAC         string  `json:"mac"`
	Name        string  `json:"name"`
	Temperature float64 `json:"temperature"`
	Humidity    float64 `json:"humidity"`
}

var (
	port           int
	influxEndpoint string
)

func init() {
	flag.IntVar(&port, "port", 8080, "Port to bind to")
	flag.StringVar(&influxEndpoint, "influx", "", "Influx endpoint to use")
}

func main() {
	flag.Parse()

	r := gin.Default()

	r.POST("/report", func(c *gin.Context) {
		b, err := ioutil.ReadAll(c.Request.Body)
		if err != nil {
			logrus.WithError(err).Error("Could not read request body")
			c.JSON(500, map[string]string{"error": fmt.Sprintf("%s", err)})
		}

		logrus.Info(string(b))
		var r report
		err = json.Unmarshal(b, &r)
		if err != nil {
			logrus.WithError(err).Error("Could not unmarshal report")
			c.JSON(500, map[string]string{"error": fmt.Sprintf("%s", err)})
			return
		}

		bp, err := influx.NewBatchPoints(influx.BatchPointsConfig{
			Database:  "sensors",
			Precision: "s",
		})

		if err != nil {
			logrus.WithError(err).Fatal("Could not create the batch point")
			c.JSON(500, map[string]string{"error": fmt.Sprintf("%s", err)})
			return
		}

		pt, err := influx.NewPoint(
			"reports",
			map[string]string{
				"mac":  r.MAC,
				"name": r.Name,
			},
			map[string]interface{}{
				"temperature": r.Temperature,
				"humidity":    r.Humidity,
			},
			time.Now(),
		)
		if err != nil {
			logrus.WithError(err).Error("Could not create the influx point")
			c.JSON(500, map[string]string{"error": fmt.Sprintf("%s", err)})
			return
		}
		bp.AddPoint(pt)

		influxClient, err := influx.NewHTTPClient(influx.HTTPConfig{
			Addr: influxEndpoint,
		})
		if err != nil {
			logrus.WithError(err).Fatal("Could not create the influx client")
		}

		err = influxClient.Write(bp)
		if err != nil {
			logrus.WithError(err).Error("Could not post the batch point")
			c.JSON(500, map[string]string{"error": fmt.Sprintf("%s", err)})
			return
		}

		logrus.WithField("mac", r.MAC).Info("Posted datapoint")

		c.JSON(200, map[string]string{
			"ok": "lel",
		})
	})

	logrus.Fatal(r.Run(fmt.Sprintf("0.0.0.0:%d", port)))
}
