/******************************************
  8x8 LED display controller
  
  Author: Dhruv Joshi
  
  This is being made expressly for the FPM project.
  8x8 red LED display was procured from local vendors.
  
  Teensy 3.1 used as the controller, and an Arduino MEGA
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
// first and foremost you need to choose your microcontroller
#define mega
// #define teensy

String row, col, inputString;  // these will capture the row and column that we want to put on

// *****************************
// This part is for Teensy only. comment it if you are using MEGA
// the next 2 arrays indicate which LEDs in the row are connected to which Teensy pin
/*
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
/**/

// **************************************  
// THESE ARE FOR THE ARDUINO MEGA
int ledrow[] = 
{
  3,   // corresponds to A
  20,
  19,
  7,
  17,
  6,
  2,
  5
    
};

int ledcol[] = 
{
  14,  // corresponds to column 0
  21,
  16,
  18,
  8,
  15,
  4,
  9
  
};
/**/

// the next 2 arrays indicate what is the active state of the particular column LED (0 - active low, 1 - active HIGH)
// but this shit doesn't work
int pinActiveCol[] = 
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
int pinActiveRow[] = 
{
  0,
  0,
  1,
  0,
  1,
  1,
  0,
  0
};

void setup() {
  // set pin modes
  for (int i=5; i<22; i++) {
    pinMode(i, OUTPUT);
  }
  
  // start by putting everything in its OFF state...
  clearkar();
  
  Serial.begin(9600);
   
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
  
  lightkaro(8,8);
  
}

void loop() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if (inChar == ',') {
      // Serial.println(inputString);
      row = inputString;
      // reset that shit
      inputString = "";
    } else {
      if (inChar == '\r') {
        col = inputString;
        // Serial.println(inputString);
        // reset that shit
        inputString = "";
        clearkar();
        lightkaro(row.toInt(), col.toInt());
      } else {
        inputString += inChar;
      }
    }
  }
}

void clearkar() {
  // clear all the LEDs and refresh that shit
  for (int j = 0; j<8; j++) {
    // rows
    digitalWrite(ledrow[j], 0);  // 0 for off
    // columns
    // digitalWrite(ledcol[j], 1);  // we want to put things in their off state
  }
}


// the function which lights up the m,n LED in the array
void lightkaro(int m, int n) {
  digitalWrite(ledrow[m], 1);
  for (int k = 0; k<8; k++) {
    if (k == n) {
      digitalWrite(ledcol[k], 0);  
    } else {
      digitalWrite(ledcol[k], 1);
    }
  } 
}
