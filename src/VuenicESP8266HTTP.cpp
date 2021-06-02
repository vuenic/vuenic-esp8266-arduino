#include "VuenicESP8266HTTP.h"

VuenicESP8266HTTP::VuenicESP8266HTTP(String apiKey) {
    _apiKey = apiKey;
}

// String Value
void VuenicESP8266HTTP::add(String key, String value) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, jsonString);    
    doc[key] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Integer Value
void VuenicESP8266HTTP::add(String key, int value) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, jsonString);    
    doc[key] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Float Value
void VuenicESP8266HTTP::add(String key, float value) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, jsonString);    
    doc[key] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Double Value
void VuenicESP8266HTTP::add(String key, double value) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, jsonString);    
    doc[key] = value;
    String newInsert;
    serializeJson(doc, newInsert);
    jsonString = newInsert;
}

// Send Data to Vuenic Platform
String VuenicESP8266HTTP::send(){
    WiFiClient client;
    HTTPClient http;
	Serial.println("[Vuenic HTTP] Connecting to "+_server+"...");
	http.begin(client, _server); 
    http.addHeader("Accept", "application/json");
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", _apiKey);
	Serial.println("[Vuenic HTTP] POST...");
	Serial.println("[Vuenic HTTP]" + jsonString);
	int httpCode = http.POST(jsonString);

    if(httpCode > 0) {
       Serial.println("[Vuenic HTTP] POST... code: "+(String)httpCode);

       if(httpCode == 201) {
           String payload = http.getString();
           Serial.println("[Vuenic HTTP] " + payload);
           Serial.println("[Vuenic HTTP] Successfull");
       }
       else {
           String payload = http.getString();
           Serial.println("[Vuenic HTTP] " + payload);
           Serial.println("[Vuenic HTTP] Error");
       }
   }
   else {
       Serial.println("[Vuenic HTTP] POST... failed, error: "+(String)http.errorToString(httpCode).c_str());
   }
   http.end();
   return (String)httpCode;
}

// Simple Wifi Connection 
bool VuenicESP8266HTTP::wifiConnection(String wifiSSID, String wifiPassword) {
    char wifiSSIDChar[wifiSSID.length()+1];
    char wifiPasswordChar[wifiPassword.length()+1];

    wifiSSID.toCharArray(wifiSSIDChar, wifiSSID.length()+1);
    wifiPassword.toCharArray(wifiPasswordChar, wifiPassword.length()+1);

    _wifiSSID = wifiSSIDChar;
    _wifiPass = wifiPasswordChar;

    WiFi.begin(_wifiSSID, _wifiPass);
    Serial.println("Connecting to " + wifiSSID + "...");

    int counter = 0;
    while(WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println(".");
        counter++;
        if(counter >= 10) {
            counter = 0;
            Serial.println("Could not connect to " + wifiSSID + "! Retrying...");
        }
    }

    Serial.println("WiFi Connected!");
    Serial.println("IP Address: " + ipToString(WiFi.localIP()));
    return true;
}

// Showing IP Address
String VuenicESP8266HTTP::ipToString(IPAddress ip){
    String s="";
    for (int i=0; i<4; i++)
        s += i  ? "." + String(ip[i]) : String(ip[i]);
    return s;
}