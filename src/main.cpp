#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>
#include "config.h"

#ifndef SENSOR_TYPE
#define SENSOR_TYPE DHT11
#endif
#ifndef DHT_PIN
#define DHT_PIN D4
#endif
#ifndef THINGSPEAK_ENABLED
#define THINGSPEAK_ENABLED 0
#endif
#ifndef PUBLISH_INTERVAL_MS
#define PUBLISH_INTERVAL_MS 15000UL
#endif

DHT dht(DHT_PIN,SENSOR_TYPE);
WiFiClient networkClient;
unsigned long lastSampleAt=0;

void connectToWiFi(){
  if(WiFi.status()==WL_CONNECTED) return;
  WiFi.mode(WIFI_STA); WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  unsigned long start=millis();
  while(WiFi.status()!=WL_CONNECTED && millis()-start<20000UL){delay(500);Serial.print('.');}
  if(WiFi.status()==WL_CONNECTED){Serial.println();Serial.print(F("Wi-Fi IP: "));Serial.println(WiFi.localIP());}
  else Serial.println(F("Wi-Fi connection timed out."));
}
bool readSensor(float &t,float &h){
  h=dht.readHumidity(); t=dht.readTemperature();
  if(isnan(h)||isnan(t)){Serial.println(F("DHT read failed."));return false;}
  if(h<0||h>100||t<-40||t>80){Serial.println(F("Reading outside expected DHT11 range."));return false;}
  return true;
}
void publish(float t,float h){
#if THINGSPEAK_ENABLED
  if(WiFi.status()!=WL_CONNECTED){Serial.println(F("No Wi-Fi; upload skipped."));return;}
  ThingSpeak.setField(1,t); ThingSpeak.setField(2,h);
  int response=ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID,THINGSPEAK_WRITE_API_KEY);
  Serial.println(response==200?F("ThingSpeak update successful."):F("ThingSpeak update failed."));
#else
  (void)t;(void)h;Serial.println(F("ThingSpeak disabled in local configuration."));
#endif
}
void setup(){
  Serial.begin(115200); delay(100); Serial.println(F("Glowlogics Project 01 - Temperature & Humidity Monitor"));
  dht.begin();
#if THINGSPEAK_ENABLED
  ThingSpeak.begin(networkClient);connectToWiFi();
#endif
}
void loop(){
  if(millis()-lastSampleAt<PUBLISH_INTERVAL_MS){delay(10);return;}
  lastSampleAt=millis();
#if THINGSPEAK_ENABLED
  if(WiFi.status()!=WL_CONNECTED)connectToWiFi();
#endif
  float t=0,h=0;if(!readSensor(t,h))return;
  Serial.print(F("Temperature: "));Serial.print(t,1);Serial.print(F(" C | Humidity: "));Serial.print(h,1);Serial.println(F(" %"));
  publish(t,h);
}