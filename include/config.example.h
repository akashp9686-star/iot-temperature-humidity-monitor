#pragma once
// Copy to config.h locally. Never commit credentials.
#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#define SENSOR_TYPE DHT11
// Glowlogics Project 01 wiring: DHT DATA -> NodeMCU D4 (GPIO2).
#define DHT_PIN D4
#define THINGSPEAK_ENABLED 0
#define THINGSPEAK_CHANNEL_ID 0
#define THINGSPEAK_WRITE_API_KEY "YOUR_WRITE_API_KEY"
// Handbook describes 10 s; ThingSpeak free tier requires >=15 s per channel.
#define PUBLISH_INTERVAL_MS 15000UL
