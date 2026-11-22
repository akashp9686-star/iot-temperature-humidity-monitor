# System Architecture

## Data flow

1. The DHT11 or DHT22 sensor measures ambient temperature and relative humidity.
2. The ESP8266 NodeMCU reads the sensor using the DHT library.
3. The firmware rejects failed reads and values outside broad plausibility limits.
4. Valid readings are printed to the Serial Monitor.
5. If ThingSpeak publishing is enabled and Wi-Fi is connected, the firmware sends temperature and humidity to channel fields 1 and 2.

## Logical view

```text
[DHT11 / DHT22]
      |
      | single-wire digital data
      v
[ESP8266 NodeMCU]
      |
      +----> [Serial Monitor]
      |
      +---- Wi-Fi (optional)
                 |
                 v
            [ThingSpeak]
             Field 1: °C
             Field 2: %RH
```

## Configuration boundaries

Hardware pin, sensor model, Wi-Fi credentials, ThingSpeak channel and write key are configuration values. The example configuration uses D2 / GPIO4 and DHT11 as defaults only; confirm them against the actual hardware before use.

## Current verification status

This architecture describes the intended firmware design. Physical sensor readings, network delivery and cloud chart updates have not been verified as part of this repository preparation.
