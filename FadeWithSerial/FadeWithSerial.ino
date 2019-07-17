int led = D4; // the PWM pin the LED is attached to 
int brightness = 0; // how bright the LED is 
int fadeAmount = 5; // how many points to fade the LED by 

void setup() { 
  Serial.begin(9600); // in setup()
  pinMode(led, OUTPUT); 
}

void loop() { 
  analogWrite(led, brightness); 
  Serial.print(1023-brightness); // in loop()
  Serial.print(" "); // in loop()
  Serial.println(brightness); // in loop()
  brightness = brightness + fadeAmount; 
  if (brightness <= 0 or brightness >= 1023) { 
    fadeAmount = -fadeAmount; 
  } 
  delay(10); 
}
