# Technical Research and Verification — Project 01

## Controller and pinout
The project targets ESP8266 NodeMCU. Handbook wiring assigns DHT11 DATA to NodeMCU D4 (GPIO2). D4 is a board label; GPIO2 is the underlying ESP8266 pin.

References: https://arduino-esp8266.readthedocs.io/ and https://docs.platformio.org/en/latest/boards/espressif8266/nodemcuv2.html

## DHT11 interface
The firmware uses Adafruit's DHT library. Handbook wiring calls for a 10kΩ pull-up between DATA and VCC. Check the exact sensor module for an onboard pull-up before fitting an additional resistor. Keep GPIO signal voltage within ESP8266 3.3V limits.

References: https://github.com/adafruit/DHT-sensor-library and https://github.com/adafruit/Adafruit_Sensor

## ThingSpeak
Field 1 stores temperature in °C; Field 2 stores relative humidity in %. The firmware uses 15 seconds between uploads to respect ThingSpeak free-tier write-rate limits. Cloud publishing is disabled in the committed example config; supply credentials privately.

Reference: https://www.mathworks.com/help/thingspeak/

## Verification
GitHub Actions compiles firmware and runs the illustrative CSV checks. A hosted compile does not prove physical sensor readings, pull-up installation, Wi-Fi association or live ThingSpeak updates. These physical/cloud tests must be performed and recorded separately.