#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define WIFI_SSID "YourNetworkName"
#define WIFI_PASSPHRASE "Passowrd"

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSPHRASE);
  // wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  //WiFi.printDiag(Serial);
  Serial.println();
}

void loop() {
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  // configure traged server and url
  http.begin("http://wifitest.adafruit.com/testwifi/index.html"); //HTTP
  Serial.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  delay(1000);
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(20000);
  Serial.println(); Serial.println(); Serial.println();
}
