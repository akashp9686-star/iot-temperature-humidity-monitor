#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

#if __has_include("config.h")
  #include "config.h"
#else
  #include "config.example.h"
#endif

#ifndef SENSOR_TYPE
  #define SENSOR_TYPE DHT11
#endif

#ifndef DHT_PIN
  #define DHT_PIN D2
#endif

#ifndef THINGSPEAK_ENABLED
  #define THINGSPEAK_ENABLED 0
#endif

#ifndef PUBLISH_INTERVAL_MS
  #define PUBLISH_INTERVAL_MS 20000UL
#endif

DHT dht(DHT_PIN, SENSOR_TYPE);
WiFiClient networkClient;

unsigned long lastSampleAt = 0;

void connectToWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;

  Serial.print(F("Connecting to Wi-Fi"));
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  const unsigned long startedAt = millis();
  while (WiFi.status() != WL_CONNECTED &&
         millis() - startedAt < 20000UL) {
    delay(500);
    Serial.print('.');
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.print(F("Wi-Fi connected. IP: "));
    Serial.println(WiFi.localIP());
  } else {
    Serial.println();
    Serial.println(F("Wi-Fi connection timed out; will retry later."));
  }
}

bool readSensor(float &temperatureC, float &humidityPercent) {
  humidityPercent = dht.readHumidity();
  temperatureC = dht.readTemperature();

  if (isnan(humidityPercent) || isnan(temperatureC)) {
    Serial.println(F("DHT read failed. Check sensor type, wiring and power."));
    return false;
  }

  if (humidityPercent < 0.0f || humidityPercent > 100.0f ||
      temperatureC < -40.0f || temperatureC > 125.0f) {
    Serial.println(F("Sensor value outside broad plausibility limits."));
    return false;
  }

  return true;
}

void publishToThingSpeak(float temperatureC, float humidityPercent) {
#if THINGSPEAK_ENABLED
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(F("Skipping cloud update: Wi-Fi is not connected."));
    return;
  }

  ThingSpeak.setField(1, temperatureC);
  ThingSpeak.setField(2, humidityPercent);

  const int response = ThingSpeak.writeFields(
    THINGSPEAK_CHANNEL_ID,
    THINGSPEAK_WRITE_API_KEY
  );

  if (response == 200) {
    Serial.println(F("ThingSpeak update successful."));
  } else {
    Serial.print(F("ThingSpeak update failed. HTTP/status code: "));
    Serial.println(response);
  }
#else
  (void)temperatureC;
  (void)humidityPercent;
  Serial.println(F("ThingSpeak publishing disabled in configuration."));
#endif
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println();
  Serial.println(F("IoT Temperature & Humidity Monitor"));

  dht.begin();

#if THINGSPEAK_ENABLED
  ThingSpeak.begin(networkClient);
  connectToWiFi();
#else
  Serial.println(F("Cloud publishing is disabled."));
#endif
}

void loop() {
  const unsigned long now = millis();
  if (now - lastSampleAt < PUBLISH_INTERVAL_MS) {
    delay(10);
    return;
  }
  lastSampleAt = now;

#if THINGSPEAK_ENABLED
  if (WiFi.status() != WL_CONNECTED) connectToWiFi();
#endif

  float temperatureC = 0.0f;
  float humidityPercent = 0.0f;

  if (!readSensor(temperatureC, humidityPercent)) return;

  Serial.print(F("Temperature: "));
  Serial.print(temperatureC, 1);
  Serial.print(F(" °C | Humidity: "));
  Serial.print(humidityPercent, 1);
  Serial.println(F(" %"));

  publishToThingSpeak(temperatureC, humidityPercent);
}
