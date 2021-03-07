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

      bool wifiConnection(String SSID, String wifiPassword);
      
    private:
      String _apiKey;
      char* _wifiSSID;
      char* _wifiPass;
      String ipToString(IPAddress ip);
};

#endif
