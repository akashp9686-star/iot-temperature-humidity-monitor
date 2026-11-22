# Evaluator Guide — Project 01

## Project
IoT Temperature & Humidity Monitor — ESP8266 NodeMCU, DHT11 and ThingSpeak.

## What to review
- Firmware: `src/main.cpp`
- Build configuration: `platformio.ini`
- Safe configuration template: `include/config.example.h`
- Architecture and wiring: `docs/architecture.md`, `docs/wiring.md`
- Verification: `docs/testing.md`, `docs/review-checklist.md`
- Illustrative sample readings and automated checks: `examples/`, `tests/`

## Reproducible software checks
1. Install PlatformIO.
2. Copy `include/config.example.h` to `include/config.h`.
3. Keep placeholder credentials for compilation; add private credentials only for live use.
4. Run `pio run`.
5. Run `python -m unittest discover -s tests -v`.

## Handbook alignment
DHT11 DATA is assigned to NodeMCU D4 / GPIO2. Handbook wiring specifies a 10kΩ pull-up between DATA and VCC; inspect the actual sensor module to avoid omitting or duplicating an onboard resistor. ThingSpeak Field 1 = temperature (°C), Field 2 = humidity (%). Firmware uses 15 seconds between updates to respect ThingSpeak free-tier minimum spacing; the handbook's nominal 10-second interval is adjusted for service limits.

## Verification boundary
Latest hosted firmware build and sample-data test status: see [GitHub Actions](https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions). Physical DHT11 readings, pull-up installation, Wi-Fi and live ThingSpeak upload are not claimed as independently tested. The optional threshold alert is not implemented.
