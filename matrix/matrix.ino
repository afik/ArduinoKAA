#include <Keypad.h>
#define data 2
#define clock 3

byte zero  = B01111110;
byte one   = B00000110;
byte two   = B11011010;
byte three = B11010110;
byte four  = B10100110;
byte five  = B11110100;
byte six   = B11111100;
byte seven = B01000110;
byte eight = B11111110;
byte nine  = B11110110;
byte hapus = B00000000;
byte s = B11110100;
byte l = B00111000;
byte e = B11111000;
byte p = B11101010;
byte t = B10111000;
byte i = B00000110;
byte g = B11110110;
byte h = B10101100;

const byte ROWS = 2; // rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = {12, 11};
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = {8, 7, 6}; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define ledpin 13

void setup()
{
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output
  pinMode(5, OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    Serial.println(key);
    switch (key)
    {
      case '1':
        analogWrite(5, 255);
        break;
      case '2':
         shiftOut(data,clock,LSBFIRST,s);
         delay(500);
         shiftOut(data,clock,LSBFIRST,l);
         delay(500);
         shiftOut(data,clock,LSBFIRST,e);
         delay(500);
         shiftOut(data,clock,LSBFIRST,e);
         delay(500);
         shiftOut(data,clock,LSBFIRST,p);
         delay(500);
         shiftOut(data,clock,LSBFIRST,hapus);
         delay(500);
         shiftOut(data,clock,LSBFIRST,t);
         delay(500);
         shiftOut(data,clock,LSBFIRST,i);
         delay(500);
         shiftOut(data,clock,LSBFIRST,g);
         delay(500);
         shiftOut(data,clock,LSBFIRST,h);
         delay(500);
         shiftOut(data,clock,LSBFIRST,t);
         break;
      case '3':
        shiftOut(data, clock, LSBFIRST, three);
        break;
      case '4':
        shiftOut(data, clock, LSBFIRST, four);
        break;
      case '5':
        shiftOut(data, clock, LSBFIRST, five);
        break;
      case '6':
        shiftOut(data, clock, LSBFIRST, six);
        break;
      default:
        break;
    }
  }
}

