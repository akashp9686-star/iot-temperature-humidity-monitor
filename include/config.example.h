#pragma once

// Copy this file to config.h and enter local settings.
// config.h is ignored by Git. Never commit credentials.

#define WIFI_SSID       "YOUR_WIFI_NAME"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"

// Confirmed project sensor.
#define SENSOR_TYPE     DHT11

// Confirmed project DATA connection:
// NodeMCU D2 maps to ESP8266 GPIO4.
#define DHT_PIN         D2

// Enable locally after entering a valid ThingSpeak channel and key.
// Keep this example disabled so credentials are never published.
#define THINGSPEAK_ENABLED 0
#define THINGSPEAK_CHANNEL_ID 0
#define THINGSPEAK_WRITE_API_KEY "YOUR_WRITE_API_KEY"

// Firmware sampling / publishing interval in milliseconds.
// 20000 ms = 20 seconds.
#define PUBLISH_INTERVAL_MS 20000UL
