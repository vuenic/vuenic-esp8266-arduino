#include "VuenicESP8266HTTP.h"

#define APIKEY "your-access-key"
#define WIFISSID "your-wifi-ssid"
#define WIFIPASSWORD "your-wifi-password"

VuenicESP8266HTTP vuenic(APIKEY);

void setup() {
  Serial.begin(9600);
  vuenic.wifiConnection(WIFISSID,WIFIPASSWORD);
}

void loop() {
  float temperature = 30.50;
  float humidity = 90.50;

  // vuenic.add(kode_sensor(int), nilai_sensor)
  vuenic.add(1, temperature);
  vuenic.add(3, humidity);
  vuenic.send();

  delay(8000);
}