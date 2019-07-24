#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "amdocs-iot.firebaseio.com"
#define FIREBASE_AUTH "ffnU3Hk7IfCQr7u05XGtPryzz8ELHGNZEvElkfg8"
#define WIFI_SSID "YourNetworkName" //set the required ssid and password
#define WIFI_PASSWORD "Password"
int ldr1 = D2, ldr2 = D3, ldr3 = D4, ldr4 = D5; //pins to be connnected to the LDR modules from NOdeMCU
int LDR1_value, LDR2_value, LDR3_value, LDR4_value;
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
  LDR1_value = digitalRead(ldr1);
  LDR2_value = digitalRead(ldr2);
  LDR3_value = digitalRead(ldr3);
  LDR4_value = digitalRead(ldr4);

  Serial.print(LDR1_value);
  Serial.print('\t');
  Serial.print(LDR2_value);
  Serial.print('\t');
  Serial.print(LDR3_value);
  Serial.print('\t');
  Serial.println(LDR4_value);


  Firebase.setInt("Parking/Slot1", LDR1_value);
  Firebase.setInt("Parking/Slot2", LDR2_value);
  Firebase.setInt("Parking/Slot3", LDR3_value);
  Firebase.setInt("Parking/Slot4", LDR4_value);
  if (Firebase.failed()) {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  delay(1000);
}
