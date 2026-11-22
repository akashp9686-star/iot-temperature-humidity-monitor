#pragma once

// Copy this file to config.h and enter local settings.
// config.h is ignored by Git. Never commit credentials.

#define WIFI_SSID       "YOUR_WIFI_NAME"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"

// Select exactly one sensor model: DHT11 or DHT22.
#define SENSOR_TYPE     DHT11

// NodeMCU D2 maps to ESP8266 GPIO4.
// Change this to match your actual wiring.
#define DHT_PIN         D2

// Set to 1 only after configuring a ThingSpeak channel.
#define THINGSPEAK_ENABLED 0
#define THINGSPEAK_CHANNEL_ID 0
#define THINGSPEAK_WRITE_API_KEY "YOUR_WRITE_API_KEY"

// Sensor sampling / publishing interval in milliseconds.
// Check current ThingSpeak update limits before reducing this interval.
#define PUBLISH_INTERVAL_MS 20000UL
