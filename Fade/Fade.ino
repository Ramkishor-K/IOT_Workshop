int led = D4;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(led, OUTPUT); 
} 

void loop() { 
  analogWrite(led, brightness); 
  brightness = brightness + fadeAmount; 
  if (brightness <= 0 or brightness >= 1023) { 
    fadeAmount = -fadeAmount; 
  }
  delay(10); 
}

