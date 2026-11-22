# IoT Temperature & Humidity Monitoring System

[![Firmware build and tests](https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions/workflows/firmware-build.yml/badge.svg)](https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions/workflows/firmware-build.yml)

An ESP8266 NodeMCU-based IoT project that reads ambient temperature and relative humidity using a **DHT11 sensor** and publishes readings to **ThingSpeak**.

> **Hardware configuration reported by the project owner:** DHT11 sensor connected to NodeMCU D2 (GPIO4). The owner reports that ThingSpeak data publishing has worked. This repository has not independently reproduced or re-tested that physical setup.

## Features

- ESP8266 NodeMCU firmware using the Arduino framework
- DHT11 temperature and humidity sensing
- Serial Monitor output
- ThingSpeak cloud publishing
- Temperature in ThingSpeak Field 1 (°C)
- Relative humidity in ThingSpeak Field 2 (%)
- Local configuration file for Wi-Fi and ThingSpeak credentials
- PlatformIO build configuration

## Confirmed project configuration

| Item | Configuration |
|---|---|
| Controller | ESP8266 NodeMCU |
| Sensor | DHT11 |
| Sensor DATA pin | D2 (GPIO4) |
| Cloud platform | ThingSpeak |
| ThingSpeak Field 1 | Temperature (°C) |
| ThingSpeak Field 2 | Relative humidity (%) |
| Firmware interval | 20 seconds |

The 20-second interval is configurable and is above the 15-second minimum commonly applied to free ThingSpeak channel updates. Check the current ThingSpeak service limits before changing it.

## Hardware requirements

- ESP8266 NodeMCU development board
- DHT11 temperature and humidity sensor
- Breadboard and jumper wires as required
- USB cable and suitable power source
- Pull-up resistor as required by the particular DHT11 sensor/module

The project owner has confirmed the DHT11 and D2 data-pin configuration. The exact sensor breakout type and whether an external pull-up resistor is installed have not been independently confirmed. The handbook calls for a 10 kΩ pull-up arrangement; check the module and actual circuit before adding or documenting one as physically installed.

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

- PlatformIO Core or PlatformIO IDE
- ESP8266 platform for PlatformIO
- Adafruit DHT sensor library
- Adafruit Unified Sensor library
- ThingSpeak library

## Configure the firmware

1. Copy `include/config.example.h` to `include/config.h`.
2. Enter your Wi-Fi SSID and password in the local `config.h`.
3. Keep `SENSOR_TYPE` set to `DHT11`.
4. Keep `DHT_PIN` set to `D2` to match the confirmed project wiring.
5. Set `THINGSPEAK_ENABLED` to `1` in your local configuration.
6. Enter your ThingSpeak Channel ID and Write API Key.
7. Never commit `config.h`, Wi-Fi credentials, or API keys.

The example configuration intentionally disables cloud publishing and contains placeholders. This prevents secrets from being published in the repository.

## Build and upload

From the repository root:

```bash
pio run
pio run --target upload
pio device monitor
```

Select the correct serial port and board upload settings for your NodeMCU. The project uses the PlatformIO `nodemcuv2` board profile as a starting point. The firmware uses a 115200 baud Serial Monitor.

## ThingSpeak channel mapping

| ThingSpeak field | Data |
|---|---|
| Field 1 | Temperature in degrees Celsius |
| Field 2 | Relative humidity in percent |

The project owner reports that ThingSpeak publishing has worked on the physical project. No live channel link or independent test capture is included in this repository yet.

## Temperature-threshold alert

The handbook describes a temperature-threshold alert as an optional extension. It is **not currently implemented** in the committed firmware. It should only be listed as a completed feature after the code is added and tested.

## Validation and testing

Run the repository's lightweight sample CSV check:

```bash
python -m unittest discover -s tests -v
```

This checks only the illustrative CSV file's structure and broad numeric ranges. It does not compile the firmware or independently test the DHT11, ESP8266, Wi-Fi connection, or ThingSpeak channel.

See [docs/testing.md](docs/testing.md) for the current verification record and remaining checks.

## Safety and limitations

- Confirm the DHT11 module's supply-voltage requirements and pin labels.
- ESP8266 GPIO uses 3.3 V logic; do not apply 5 V to GPIO.
- Keep Wi-Fi credentials and ThingSpeak API keys out of version control.
- The physical configuration is owner-reported; independent hardware re-testing remains outstanding.
- No project photographs or live ThingSpeak dashboard URL have been supplied for this repository update.

## References

- [ESP8266 Arduino Core documentation](https://arduino-esp8266.readthedocs.io/)
- [Adafruit DHT sensor library](https://github.com/adafruit/DHT-sensor-library)
- [ThingSpeak documentation](https://www.mathworks.com/help/thingspeak/)

## License

This project is provided under the MIT License. See [LICENSE](LICENSE).
