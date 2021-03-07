#ifndef Vuenic8266MQTT_H
#define Vuenic8266MQTT_H
#include <Arduino.h>
#include <ArduinoJson.h>

class VuenicESP8266MQTT
{
    public:
      VuenicESP8266MQTT(String apiKey);
    
    private:
      String _apiKey;
};

#endif
