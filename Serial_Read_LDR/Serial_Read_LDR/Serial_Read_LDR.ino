
int ldr1 = D2, ldr2 = D3, ldr3 = D4, ldr4 = D5; //pins to be connnected to the LDR modules from NodeMCU
int LDR1_value, LDR2_value, LDR3_value, LDR4_value; // Variables to store the data
void setup() {
  
  Serial.begin(9600);

}

void loop() {
  //Read the LDR values
  LDR1_value = digitalRead(ldr1);
  LDR2_value = digitalRead(ldr2);
  LDR3_value = digitalRead(ldr3);
  LDR4_value = digitalRead(ldr4);

  //Serial print the LDR values
  Serial.print(LDR1_value);
  Serial.print('\t');
  Serial.print(LDR2_value);
  Serial.print('\t');
  Serial.print(LDR3_value);
  Serial.print('\t');
  Serial.println(LDR4_value);
}
