# Wiring Guide

> The following is a reference wiring arrangement, not proof of the exact connections used in the completed physical build. Confirm the actual sensor model and board pinout before connecting power.

## Reference connections

| DHT sensor pin | NodeMCU connection | Notes |
|---|---|---|
| VCC | 3V3 | Use the sensor module's specified supply range |
| GND | GND | Common ground |
| DATA | D2 (GPIO4) | Matches the example firmware configuration |

For a bare DHT sensor (rather than a breakout module), a pull-up resistor between DATA and VCC is commonly required; consult the sensor datasheet/module documentation. Many breakout boards already include this resistor.

## Important electrical notes

- ESP8266 GPIO uses 3.3 V logic. Do not drive an ESP8266 GPIO with 5 V.
- Do not assume every DHT breakout has the same pin order; check its labels and datasheet.
- Power down before changing wiring.
- The firmware default is DHT11 on D2. For DHT22, change `SENSOR_TYPE` in the local configuration.
- If the actual project uses a different data pin, update `DHT_PIN` as well.

## Before powering on

1. Identify whether the sensor is DHT11 or DHT22.
2. Verify VCC, GND and DATA labels on the actual module.
3. Verify the NodeMCU pin mapping.
4. Check for shorts and ensure the GPIO signal never exceeds 3.3 V.
5. Only then connect USB power.
