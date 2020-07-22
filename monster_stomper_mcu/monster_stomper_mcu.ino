#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

int prevSwitchState = LOW;
int switchState = LOW;

String serverIp = "192.168.2.158";
const char * wifiName = "Wifi name here";
const char * wifiPassword = "Wifi password here";

int switchPin = D1;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);

  Serial.begin(115200);

  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(wifiName, wifiPassword);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.println("Waiting to connect to wifi");
    delay(1000);
  }

}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    switchState = digitalRead(switchPin);

    if (switchState != prevSwitchState) {

      WiFiClient client;

      HTTPClient http;

      Serial.print("[HTTP] begin...\n");
      if (http.begin(client, "http://"+ serverIp + ":3000/")) {  // HTTP

        Serial.println("[HTTP] GET...");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled
          Serial.printf("[HTTP] GET... code: %d\n", httpCode);

          // file found at server
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = http.getString();
            Serial.println(payload);
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
      } else {
        Serial.println("[HTTP] Unable to connect\n");
      }
      delay(1000);

      prevSwitchState = digitalRead(switchPin);
    }
  }

}
