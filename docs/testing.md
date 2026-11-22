# Testing and Verification — Project 01

| Check | Status |
|---|---|
| PlatformIO ESP8266 firmware build | Passed — [latest relevant run](https://github.com/akashp9686-star/iot-temperature-humidity-monitor/actions/runs/45002575353) |
| Sample CSV validation tests | Passed in same run |
| DHT11 physical reading | Not verified |
| D4 / GPIO2 physical wiring | Not independently verified |
| 10kΩ pull-up presence/value | Must be inspected on actual sensor/module |
| Wi-Fi connection | Not verified |
| ThingSpeak upload / live dashboard | Not verified |
| Genuine project photographs | Not supplied |

## Local software test
```bash
python -m unittest discover -s tests -v
```

The CSV tests validate illustrative sample-data structure and broad numeric ranges. They do not simulate the DHT protocol or verify hardware.

## Hardware checklist
- [ ] Confirm DHT11 VCC, GND and DATA labels.
- [ ] Connect DATA to NodeMCU D4 / GPIO2.
- [ ] Verify the handbook 10kΩ pull-up between DATA and VCC; check for an onboard resistor before adding one.
- [ ] Keep ESP8266 GPIO logic within 3.3V.
- [ ] Upload firmware and observe temperature/humidity in Serial Monitor.
- [ ] If enabled, confirm ThingSpeak Field 1 and Field 2 updates at the configured 15-second interval.
- [ ] Record date, board/sensor revision and genuine observations.

Do not mark physical or cloud checks passed until performed.
