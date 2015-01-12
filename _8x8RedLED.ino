/******************************************
  8x8 RGB LED display controller
  
  Author: Dhruv Joshi
  
  This is being made expressly for the FPM project.
  8x8 red RGB LED was procured from ebay India
  
  Arduino MEGA 2560 used as the controller.
  Digital pins 22 - 52 (even) used for pins 32 - 17 resp. 
  and 23 - 53 (odd) pins used for pins 16 - 1 resp of the RGB Matrix
    
  The pinout of the 8x8 LED array is given on http://www.ebay.in/itm/8x8-RGB-LED-Matrix-Common-Anode-Diffused-Arduino-Full-Colour-RGB-Color-60mm-/151453142648?aff_source=vizury
  basically, the pins are from 1 - 16 (one set) and 17 - 32 (the other set)
  
  The map for the RED:
  
            9 10 11 12 13 14 15 16
          __|__|__|__|__|__|__|__|__
     17  |                         |
     18  |                         |
     19  |                         |
     20  |                         |
     29  |                         |
     30  |                         |
     31  |                         |
     32  |                         |
         |-------------------------|
  
  The map for the GREEN:
  
           28 27 26 25 24 23 22 21
          __|__|__|__|__|__|__|__|__
     17  |                         |
     18  |                         |
     19  |                         |
     20  |                         |
     29  |                         |
     30  |                         |
     31  |                         |
     32  |                         |
         |-------------------------|
         
   The map for the BLUE:
   
            1  2  3  4  5  6  7  8
          __|__|__|__|__|__|__|__|__
     17  |                         |
     18  |                         |
     19  |                         |
     20  |                         |
     29  |                         |
     30  |                         |
     31  |                         |
     32  |                         |
         |-------------------------|

   Remember that all this is on the same board. 
   
   And our pin map is as follows: 
   (MEGA - RGB array)
   
   22 - 32                      23 - 16
   24 - 31                      25 - 15
   26 - 30                      27 - 14
   ...                          ...
   52 - 17                      53 - 1
   
   mega = 86 - 2*rgb            mega = 55 - 2*rgb
   
   
*******************************************/
char color, row, column;
String inputString;  // these will capture the row and column that we want to put on

// red column pins on the mega
int redcol[] = 
{
  // rgb pins are 
  //  9, 10, 11, 12, 13, 14, 15, 16
  // mega pins...
     37, 35, 33, 31, 29, 27, 25, 23
};

// green...
int greencol[] = 
{
  // rgb pins are 
  // 28, 27, 26, 25, 24, 23, 22, 21
  // mega pins...
  // 30, 32, 34, 36, 38, 40, 42, 44    apparently thisis reverse .. wtf
     44, 42, 40, 38, 36, 34, 32, 30
};

// blue...
int bluecol[] = 
{
  // rgb pins are 
  //  1,  2,  3,  4,  5,  6,  7,  8,
  // mega pins...
     53, 51, 49, 47, 45, 43, 41, 39
};

// and finally the fixed rows..
// these are the anodes, +ve voltage here
int rows[] = 
{
    // rgb pins are 
    // 17, 18, 19, 20, 29, 30, 31, 32
    // mega pins are
       52, 50, 48, 46, 28, 26, 24, 22
};

void setup() {
  // set pin modes
  for (int j=22; j<54; j++) {
    pinMode(j, OUTPUT);
  }
  
  // start by putting everything in its OFF state...
  clearkar();
  
  Serial.begin(9600);
  
  // then putting ON red (0,0)
  /*
  digitalWrite(rows[0], HIGH);
  digitalWrite(bluecol[2], LOW);
  /**/
}

void loop() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    /*
    if (inChar == ',') {
      // Serial.println(inputString);
      row = inputString;
      // reset that shit
      inputString = "";
    } else {
      */
      if (inChar == '\n') {
        // end of line hapens at \r\n. Seperate values out
        if (inputString.length() == 4) {  // one extra for the '\n'
          color = inputString[0];
          row = inputString[1];
          column = inputString[2];
          
          if (int(row) - 48 > 7 || int(column) - 48 > 7) {
            Serial.println("digits out of range");
          } else {          
          // reset that shit
            inputString = "";
            clearkar();
            lightkaro(color, int(row), int(column));
          }
        } else if (inputString[0] == 'x') {
          clearkar();
        } else {
          Serial.println("something's wrong, check entry"); 
          inputString = "";
        }
      } else {
        inputString += inChar;
      }
    //}
  }
}

void clearkar() {
  // clear all the LEDs and refresh that shit
  // setting everything off first...  
  for(int i = 0; i<8; i++) {
    digitalWrite(rows[i], LOW);
    digitalWrite(redcol[i], HIGH);
    digitalWrite(bluecol[i], HIGH);
    digitalWrite(greencol[i], HIGH);
  } 
}


// the function which lights up the m,n LED in the array
void lightkaro(char c, int m, int n) {
  // we will subtract 48 because otherwise it will be the 
  // ascii int representation of the int value and not its actual value
  Serial.print(c);
  Serial.print(" | ");
  Serial.print(m-48);
  Serial.print(" | ");
  Serial.print(n-48);
  Serial.println(" | ");
  
  // first light up the row (since they're common)..
  digitalWrite(rows[m-48], HIGH);
  
  // switch column case based on color...
  switch(c) {
    case 'r':
    {
    // this is for the case of red
      digitalWrite(redcol[n-48], LOW);
      break;
    }
    case 'g':
    {
    // this is for the case of green
      digitalWrite(greencol[n-48], LOW);
      break;
    }
    case 'b':
    {
    // this is for the case of blue
      digitalWrite(bluecol[n-48], LOW);
      break;
    }
    default:
      Serial.println("first character not matching r,g,b.");
  }
}
