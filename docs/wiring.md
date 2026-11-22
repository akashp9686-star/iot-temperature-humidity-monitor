# Wiring Guide

## Confirmed project configuration

The project owner confirmed that the physical build uses a **DHT11 sensor** and that its DATA signal is connected to **NodeMCU D2 (GPIO4)**.

The table below documents the reported configuration. The exact breakout-board pin order and physical pull-up resistor installation have not been independently inspected.

| DHT11 connection | NodeMCU connection | Notes |
|---|---|---|
| VCC | 3V3, if supported by the specific module | Check the module's rated supply voltage |
| GND | GND | Common ground |
| DATA | D2 (GPIO4) | Confirmed by project owner |

## Pull-up resistor

The Glowlogics handbook specifies a 10 kΩ pull-up resistor between DATA and VCC. Whether this resistor is already present on the sensor breakout or installed externally in the actual build has not been confirmed. Inspect the module and circuit before adding another resistor or claiming that it is installed.

## Electrical notes

- ESP8266 GPIO uses 3.3 V logic. Do not apply 5 V to an ESP8266 GPIO.
- Do not assume every DHT11 module has the same pin order; check its labels and documentation.
- Check the supply-voltage requirements of the exact DHT11 module.
- Power down before changing wiring.
- The firmware configuration must use `SENSOR_TYPE DHT11` and `DHT_PIN D2` to match the reported build.

## Pre-power checklist

1. Confirm the DHT11 module's VCC, GND and DATA labels.
2. Confirm DATA is connected to NodeMCU D2 (GPIO4).
3. Check whether the module already includes a pull-up resistor.
4. Verify that the ESP8266 GPIO signal does not exceed 3.3 V.
5. Check for shorts before connecting USB power.

> This document records the project owner's reported wiring. Add a genuine photograph of the assembled circuit when available so the wiring can be visually reviewed.
