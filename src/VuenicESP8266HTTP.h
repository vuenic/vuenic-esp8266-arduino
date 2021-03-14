#ifndef VuenicESP8266HTTP_H
#define VuenicESP8266HTTP_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class VuenicESP8266HTTP
{
    public:
      VuenicESP8266HTTP(String apiKey);
      void begin();
      void add(String key, String value);
      void add(String key, int value);
      void add(String key, float value);
      void add(String key, double value);
      String send();
      bool wifiConnection(String wifiSSID, String wifiPassword);
      
    private:
      String _apiKey;
      String _server = "http://api.vuenic.com/v1/devices/";
      String _port = "80";
      String jsonString = "{}";
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif
