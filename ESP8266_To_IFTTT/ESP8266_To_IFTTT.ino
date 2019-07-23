#include <ESP8266WiFi.h>
#include <arduino.h>
#include "DataToMaker.h"

#define SERIAL_DEBUG

const char* myKey = "kxQAMSTTkoMnTTvHm5_aVh2KUdSiRqJrW38oazqcrWX"; // your maker key here
const char* ssid = "YouNetworkName"; // your router ssid here
const char* password = "Password"; // your router password here

String projectName = "*****";//project name here

// declare new maker event with the name "ESP"
DataToMaker event(myKey, projectName);

bool connectedToWiFI = false;

bool ConnectWifi();
void setup()
{
  Serial.begin(115200);
  delay(200);
  Serial.println();

  delay(10); // short delay
  WiFi.mode(WIFI_STA);
  ConnectWifi();
}

void loop() {
  if (wifiConnected) {

    //event.setValue(1, String("5"));
    //event.setValue(2, String("23"));

    debugln("connecting...");
    if (event.connect()) {
      debugln("Connected To Maker");
      event.post();
    }
    else debugln("Failed To Connect To Maker!");

    delay(10000); // pause for 1 second
    //digitalWrite(HEARTBEAT_PIN, !digitalRead(HEARTBEAT_PIN));
  }
  else
  {
    delay(60 * 1000); // 1 minute delay before trying to re connect
    ConnectWifi();
  }
}

bool ConnectWifi()
{
  // Connect to WiFi network
  debugln();
  debugln();
  debug("Connecting to ");
  debugln(ssid);
  unsigned long startTime = millis();
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED && startTime + 30 * 1000 >= millis()) {
    delay(500);
    debug(".");
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    debugln("");
    debugln("WiFi connected");
  }
  else
  {
    WiFi.disconnect();
    debugln("");
    debugln("WiFi Timed Out!");
  }
}

bool wifiConnected()
{
  return WiFi.status() == WL_CONNECTED;
}


void debug(String message)
{
#ifdef SERIAL_DEBUG
  Serial.print(message);
#endif
}

void debugln(String message)
{
#ifdef SERIAL_DEBUG
  Serial.println(message);
#endif
}

void debugln()
{
#ifdef SERIAL_DEBUG
  Serial.println();
#endif
}


