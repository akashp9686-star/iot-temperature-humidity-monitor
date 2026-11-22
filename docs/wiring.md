# Wiring Guide

## Confirmed project configuration

The project owner confirmed that the physical build uses a **DHT11 sensor** and that its DATA signal is connected to **NodeMCU D2 (GPIO4)**.

The pull-up resistor arrangement is **not yet known**. The owner has not confirmed whether a separate resistor was installed or whether the DHT11 module includes one. This document deliberately does not claim that a 10 kΩ resistor is present.

| DHT11 connection | NodeMCU connection | Notes |
|---|---|---|
| VCC | Appropriate supply for the exact DHT11 module | Check the module's rated supply voltage and pin labels |
| GND | GND | Common ground |
| DATA | D2 (GPIO4) | Confirmed by project owner |

## Pull-up resistor — verification required

The Glowlogics handbook specifies a **10 kΩ pull-up resistor between DATA and VCC**.

The actual build's pull-up arrangement has not been verified. Before treating the wiring as fully compliant:

1. Inspect the DHT11 board and determine whether it is a bare sensor or a module.
2. Check the module documentation or markings to determine whether a pull-up resistor is already fitted.
3. If the required pull-up is absent, add the handbook-specified 10 kΩ resistor between DATA and the appropriate supply, ensuring the DATA signal remains safe for the ESP8266's 3.3 V GPIO.
4. Do not add a second resistor blindly if the module already includes one.
5. Record the verified arrangement and, if possible, add a genuine photograph of the actual circuit.

**Current status:** Pull-up resistor presence/value = **Unknown / not yet verified**. The handbook requirement is 10 kΩ; this is a requirement to check against the physical circuit, not a claim that the resistor is already installed.

## Electrical notes

- ESP8266 GPIO uses 3.3 V logic. Do not apply 5 V to an ESP8266 GPIO.
- Do not assume every DHT11 module has the same pin order; check its labels and documentation.
- Check the supply-voltage requirements of the exact DHT11 module.
- Power down before changing wiring.
- The firmware configuration must use `SENSOR_TYPE DHT11` and `DHT_PIN D2` to match the reported build.

## Pre-power checklist

- [ ] Confirm the DHT11 module's VCC, GND and DATA labels.
- [ ] Confirm DATA is connected to NodeMCU D2 (GPIO4).
- [ ] Identify whether the sensor is a bare DHT11 or a breakout module.
- [ ] Verify whether a pull-up resistor is present and confirm its value.
- [ ] If required, fit the handbook-specified 10 kΩ pull-up safely.
- [ ] Verify that the ESP8266 GPIO signal does not exceed 3.3 V.
- [ ] Check for shorts before connecting USB power.

> This document records the project owner's reported wiring. Add a genuine photograph of the assembled circuit when available so the wiring and pull-up arrangement can be visually reviewed.
