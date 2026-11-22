# Project 01 — Handbook Wiring
| DHT11 pin | NodeMCU |
|---|---|
| VCC | 3V3 |
| GND | GND |
| DATA | D4 / GPIO2 |

Fit a 10 kΩ pull-up resistor between DATA and VCC as required by the handbook. Verify whether the exact sensor breakout already includes a pull-up before adding one; do not assume it is present. Keep DATA logic within ESP8266 3.3 V limits.

ThingSpeak: Field 1 temperature °C; Field 2 relative humidity %. Use a 15-second update interval for the free-tier minimum spacing.
