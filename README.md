# Project 01 — IoT Temperature & Humidity Monitor
**Glowlogics IoT Projects Handbook | EASY | ESP8266 NodeMCU + DHT11 + ThingSpeak**

This project reads ambient temperature and relative humidity with a DHT11 sensor, prints readings to Serial Monitor and publishes them to ThingSpeak.

## Handbook-aligned configuration
- Controller: ESP8266 NodeMCU.
- Sensor: DHT11 (DHT22 is an allowed handbook alternative).
- DHT VCC -> 3V3; GND -> GND; DATA -> D4 (GPIO2).
- 10 kΩ pull-up resistor between DATA and VCC as specified by the handbook.
- ThingSpeak Field 1 = temperature (°C); Field 2 = humidity (%).
- Publish interval configured to 15 seconds to respect the ThingSpeak free-tier minimum interval. The handbook's nominal 10-second description is adjusted for the service limit.

## Components
NodeMCU, DHT11, breadboard, jumper wires, 10 kΩ resistor, Micro-USB cable and Wi-Fi router.

## Firmware setup
Install ESP8266 Arduino core, Adafruit DHT sensor library, Adafruit Unified Sensor and ThingSpeak library. Copy `include/config.example.h` to `include/config.h`, add private Wi-Fi and ThingSpeak credentials, and enable `THINGSPEAK_ENABLED`. Never commit secrets.

Build with `pio run`; upload with `pio run -t upload`; monitor at 115200 baud.

## Verification boundary
Firmware and documentation are aligned to the handbook pinout. Confirm the physical pull-up resistor and D4 wiring on the actual circuit. Do not claim hardware, Wi-Fi or live ThingSpeak tests unless performed and recorded. Automated compilation is not physical validation.

## Safety
ESP8266 GPIO is 3.3 V logic; never apply 5 V to D4. Check the exact DHT11 pin labels and supply requirements before powering.
