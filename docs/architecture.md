# System Architecture — Project 01

1. DHT11 measures ambient temperature and relative humidity.
2. ESP8266 NodeMCU reads the sensor using the Adafruit DHT library.
3. Firmware rejects failed or implausible readings.
4. Valid readings are printed to Serial Monitor.
5. When enabled, Wi-Fi sends temperature and humidity to ThingSpeak.

## Handbook pin mapping
DHT11 VCC -> 3V3; GND -> GND; DATA -> NodeMCU D4 / GPIO2. The handbook specifies a 10kΩ pull-up between DATA and VCC; inspect the actual sensor module to confirm whether a pull-up is already fitted.

ThingSpeak Field 1 = temperature (°C); Field 2 = relative humidity (%). Firmware uses a 15-second publish interval to respect the free-tier write interval.

Physical sensor, network and cloud operation remain unverified.