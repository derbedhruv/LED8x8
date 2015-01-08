/******************************************
  8x8 LED display controller
  
  Author: Dhruv Joshi
  
  This is being made expressly for the FPM project.
  8x8 red LED display was procured from local vendors.
  
  Teensy 3.1 used as the controller.
  Digital pins 5-12 and 13-21 used respectively for the 
  -ve and +ve terminals

*******************************************/
void setup() {
  Serial.begin(9600);
  
  for(int i=5; i<22; i++) {
    pinMode(i, OUTPUT);
  }
  /*
  for (int j=5; j<13; j++) {
    digitalWrite(j, LOW); 
  }
  for (int k=13; k<22; k++) {
    digitalWrite(k, HIGH); 
  }
  */
  digitalWrite(5, LOW);  // COLUMN 6 TEENSY UP LOW
  digitalWrite(6, LOW);  // COLUMN 2 TEENSY UP LOW
  digitalWrite(7, HIGH);  // ROW E TEENSY UP HIGH
  digitalWrite(8, LOW);  // COLUMN 0 TEENSY UP LOW
  digitalWrite(9, HIGH);  // ROW C TEENSY UP HIGH
  digitalWrite(10, HIGH);  // ROW B TEENSU UP HIGH
  digitalWrite(11, HIGH);  // COL 1 TEENSY UP LOW
  digitalWrite(12, HIGH);  // COL 3 TEENSY UP LOW
  
  // digitalWrite(13, HIGH);
  digitalWrite(14, HIGH);    // ROW H teensy up high
  digitalWrite(15, HIGH);    // riw G teensy up high
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);  // ROW A TEENSY UP high
  digitalWrite(18, LOW);   // column 5 teensy up low
  digitalWrite(19, HIGH);  // row F teensy up HIGH
  digitalWrite(20, HIGH);  // ROW D TEENSY UP HIGH
  digitalWrite(21, LOW);  // COLUmn 8 teensy up low
}

void loop() {
  
}
