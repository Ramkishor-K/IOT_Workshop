#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "amdocs-iot.firebaseio.com"  // firbase URL
#define FIREBASE_AUTH "ffnU3Hk7IfCQr7u05XGtPryzz8ELHGNZEvElkfg8" // AUTH KEY
#define WIFI_SSID "YourNetworkName" 
#define WIFI_PASSWORD "Password"
int relay1 = D2, relay2 = D3, relay3 = D4, relay4 = D5, pir = D6;//pins to be connected to relay modules from NodeMCU module(for now ignore PIR)
int Relay1_value, Relay2_value, Relay3_value, Relay4_value;
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

  Relay1_value = Firebase.getInt("Home/val1");
  Relay2_value = Firebase.getInt("Home/val2");
  Relay3_value = Firebase.getInt("Home/val3");
  Relay4_value = Firebase.getInt("Home/val4");
  //digitalRead(pir);
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  Serial.print(Relay1_value);
  Serial.print('\t');
  Serial.print(Relay2_value);
  Serial.print('\t');
  Serial.print(Relay3_value);
  Serial.print('\t');
  Serial.println(Relay4_value);

  if (Relay1_value == 1)
  {
    digitalWrite(relay1, HIGH);
  }
  if (Relay1_value == 0)
  {
    digitalWrite(relay1, LOW);
  }
  
  if (Relay2_value == 1)
  {
    digitalWrite(relay2, HIGH);
  }
  if (Relay2_value == 0)
  {
    digitalWrite(relay2, LOW);
  }
  
  if (Relay3_value == 1)
  {
    digitalWrite(relay3, HIGH);
  }
  if (Relay3_value == 0)
  {
    digitalWrite(relay3, HIGH);
  }
  
  if (Relay4_value == 1)
  {
    digitalWrite(relay4, HIGH);
  }
  if (Relay4_value == 0)
  {
    digitalWrite(relay4, HIGH);
  }
  delay(1);
}
