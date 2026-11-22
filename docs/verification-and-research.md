# Technical Research and Verification Notes

This project uses an ESP8266 NodeMCU, a DHT11 temperature/humidity sensor and an optional ThingSpeak cloud channel.

## 1. Controller and GPIO mapping

The repository selects PlatformIO's `nodemcuv2` board environment and the Espressif 8266 Arduino framework. The example configuration uses NodeMCU board label D2 for the DHT11 data connection. On the ESP8266 NodeMCU pin mapping, D2 corresponds to GPIO4.

Confirm the exact board pinout before wiring because ESP8266 module labels and raw GPIO numbers are not interchangeable.

References:
- ESP8266 Arduino Core documentation: https://arduino-esp8266.readthedocs.io/
- PlatformIO NodeMCU v2 board definition: https://docs.platformio.org/en/latest/boards/espressif8266/nodemcuv2.html

## 2. DHT11 sensor interface

The firmware uses Adafruit's DHT sensor library and initializes it with the configured sensor type and data pin. It reads relative humidity and temperature in Celsius. The code rejects failed (NaN) readings and values outside broad plausibility bounds before printing or attempting cloud publication.

The example configuration selects DHT11 and D2 based on the project configuration supplied by the owner. The physical pull-up resistor arrangement was not confirmed; follow the exact sensor/module datasheet and the project's wiring guide before assembly.

References:
- Adafruit DHT sensor library: https://github.com/adafruit/DHT-sensor-library
- Adafruit Unified Sensor library: https://github.com/adafruit/Adafruit_Sensor

## 3. ThingSpeak data model

When enabled in a private local configuration, the firmware sends temperature to ThingSpeak Field 1 and relative humidity to Field 2 using the ThingSpeak Arduino library. Cloud publishing is disabled in the committed example configuration so credentials are not required for a clean repository build.

The sample CSV is explicitly labelled illustrative. It is test data for validating the file format, not measurements from a physical sensor.

References:
- MathWorks ThingSpeak documentation: https://www.mathworks.com/help/thingspeak/
- ThingSpeak Arduino library: https://github.com/mathworks/thingspeak-arduino

## 4. Sampling interval

The example firmware interval is 20 seconds. If cloud publishing is enabled, confirm the current write-rate limits for the selected ThingSpeak plan and channel before deployment. A successful compile does not establish that the cloud service accepted a write.

## 5. Automated verification

GitHub Actions runs PlatformIO compilation using the committed example configuration, then runs Python unit tests against the illustrative CSV file. This checks source compatibility with the selected PlatformIO environment and validates the sample file's columns, numeric parsing and broad value bounds.

Workflow: https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions/workflows/firmware-build.yml

## 6. What is and is not verified

| Item | Evidence available in this repository |
|---|---|
| ESP8266 firmware compilation | GitHub Actions PlatformIO build |
| Sample CSV format and numeric checks | Automated Python unit tests |
| DHT11 sensor readings | Not physically verified |
| Actual pull-up resistor installation | Not confirmed |
| Firmware upload to NodeMCU | Not physically verified |
| Wi-Fi connection | Not physically verified |
| ThingSpeak account/channel update | Not independently verified in this repository |
| Temperature/humidity accuracy | Not measured or calibrated |

Do not interpret the CI build as a physical device test. Add only genuine measurements, logs and photographs if those become available.
