# IoT Temperature & Humidity Monitoring System

An ESP8266 NodeMCU-based project intended to read ambient temperature and relative humidity from a DHT11 or DHT22 sensor and optionally publish readings to ThingSpeak.

> **Project status:** This repository contains a documented firmware implementation and setup materials. The contents have not been physically tested or verified against the author's exact assembled circuit in this repository update. Do not interpret example data as measured results.

## Features

- ESP8266 NodeMCU firmware using the Arduino framework
- DHT11 / DHT22 selection through a configuration setting
- Serial output for temperature and humidity readings
- Optional ThingSpeak channel publishing
- Credentials kept out of source control
- PlatformIO build configuration
- Wiring, architecture, setup and validation documentation

## Hardware target

- ESP8266 NodeMCU development board
- DHT11 or DHT22 temperature/humidity sensor (select the model in configuration)
- USB cable and suitable power source
- Jumper wires and breadboard as required

The default data pin in the example configuration is NodeMCU **D2 (GPIO4)**. Confirm this against the actual wiring before powering the circuit. Sensor type and pin assignments must match the physical build.

## Repository layout

```text
.
├── README.md
├── platformio.ini
├── include/
│   └── config.example.h
├── src/
│   └── main.cpp
├── docs/
│   ├── architecture.md
│   ├── wiring.md
│   └── testing.md
├── examples/
│   └── sample_readings.csv
├── tests/
│   └── test_sample_readings.py
├── .gitignore
└── LICENSE
```

## Software requirements

- PlatformIO Core / PlatformIO IDE
- ESP8266 platform for PlatformIO
- Libraries declared in `platformio.ini`: Adafruit DHT sensor library, Adafruit Unified Sensor, and ThingSpeak

## Configure

1. Copy `include/config.example.h` to `include/config.h`.
2. Enter your Wi-Fi SSID and password in `config.h`.
3. Choose `DHT11` or `DHT22` for `SENSOR_TYPE`.
4. Set `DHT_PIN` to the GPIO connected to the sensor data pin.
5. To publish to ThingSpeak, set `THINGSPEAK_ENABLED` to `1`, then enter your channel number and **Write API Key**.
6. Never commit `config.h` or publish your Wi-Fi password / API key.

If ThingSpeak is not configured, leave `THINGSPEAK_ENABLED` set to `0`; readings are still printed to the Serial Monitor.

## Build and upload

From the repository root:

```bash
pio run
pio run --target upload
pio device monitor
```

Select the correct serial port and board upload settings for your NodeMCU. The project uses the PlatformIO `nodemcuv2` board profile as a starting point.

## ThingSpeak fields

When enabled, the firmware writes:
- Field 1: temperature in degrees Celsius
- Field 2: relative humidity in percent

ThingSpeak channel publishing is rate-limited by the service. The default firmware interval is 20 seconds; adjust it to comply with the current limits of your account and service.

## Validation

Run the repository's lightweight CSV example check with:

```bash
python -m unittest discover -s tests -v
```

This checks only the format and numeric ranges of the illustrative CSV file. It does **not** validate a sensor, ESP8266 board, Wi-Fi connection or ThingSpeak deployment. See [docs/testing.md](docs/testing.md).

## Safety and limitations

- Use the correct supply voltage for your specific sensor module.
- ESP8266 GPIO is 3.3 V logic; do not apply 5 V to GPIO.
- Confirm the actual sensor model and data pin before uploading firmware.
- Network credentials and ThingSpeak keys are local configuration, not repository content.
- Hardware operation, sensor accuracy, Wi-Fi connectivity and cloud updates remain unverified until tested on the actual assembly.

## References

- [ESP8266 Arduino Core documentation](https://arduino-esp8266.readthedocs.io/)
- [Adafruit DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [ThingSpeak documentation](https://www.mathworks.com/help/thingspeak/)

## License

This project is provided under the MIT License. See [LICENSE](LICENSE).
