/******************************************
  8x8 LED display controller
  
  Author: Dhruv Joshi
  
  This is being made expressly for the FPM project.
  8x8 red LED display was procured from local vendors.
  
  Teensy 3.1 used as the controller.
  Digital pins 5-12 and 14-21 used respectively for the 
  -ve and +ve terminals
  The pinout of the 8x8 LED array is as follows:
  (The orientation is such that the printed text "1088A5" is 
  written on the left side of the array
  
  H - active HIGH
  L - active LOW
  
             0 1 2 3 4 5 6 7 8
    3L   -|-----------------| A - HH
 1  1L   -|                 | B - GH
 0  BH   -|                 | C - 6L
 8  CH   -|                 | D - AH
 8  0L   -|                 | E - 4L
 A  EH   -|                 | F - FH
 5  2L   -|                 | G - DH
    5L   -|-----------------| H - 7L
  

*******************************************/
int ledrow[] = 
{
  17,   // pin 17 corresponds to A
  10,
  9,
  20,
  7,
  19,
  15,
  14
};

int ledcol[] = 
{
  8,  // pin 8 corresponds to column 0
  11,
  6,
  12,
  18,
  5,
  16,
  21
};

int pinOffStateCol[] = 
{
  1,
  1,
  0,
  1,
  0,
  1,
  1,
  0
};


void setup() {
  // start by putting everything in its OFF state...
  
  
  Serial.begin(9600);
  
  for(int i=5; i<22; i++) {
    pinMode(i, OUTPUT);
  }
  
  /*
  digitalWrite(5, 0);  // COLUMN 5 TEENSY UP LOW
  digitalWrite(6, 0);  // COLUMN 2 TEENSY UP LOW
  digitalWrite(7, 1);  // ROW E TEENSY UP HIGH
  digitalWrite(8, 0);  // COLUMN 0 TEENSY UP LOW
  digitalWrite(9, 1);  // ROW C TEENSY UP HIGH
  digitalWrite(10, 1);  // ROW B TEENSU UP HIGH
  digitalWrite(11, 0);  // COL 1 TEENSY UP LOW
  digitalWrite(12, 0);  // COL 3 TEENSY UP LOW
  
  digitalWrite(14, 1);    // ROW H teensy up high
  digitalWrite(15, 1);    // riw G teensy up high
  digitalWrite(16, 0);    // COLUMN 6 TEENSY UP LOW
  digitalWrite(17, 1);  // ROW A TEENSY UP high
  digitalWrite(18, 0);   // column 4 teensy up low
  digitalWrite(19, 1);  // row F teensy up HIGH
  digitalWrite(20, 1);  // ROW D TEENSY UP HIGH
  digitalWrite(21, 0);  // COLUmn 7 teensy up low
  */
}

void loop() {
  
}
