#ifndef Vuenic8266HTTP_H
#define Vuenic8266HTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

class VuenicESP8266HTTP
{
    public:
      VuenicESP8266HTTP(String apiKey);
      void begin();
      void add(String key, String value);
      void add(String key, int value);
      void add(String key, float value);
      void add(String key, double value);
      bool wifiConnection(String SSID, String wifiPassword);
      
    private:
      String _apiKey;
      String jsonString = "{}";
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif
