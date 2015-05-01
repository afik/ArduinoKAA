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

void setup() {
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output
     
}

void loop() {
  shiftOut(data, clock, LSBFIRST, zero);
    delay(500);
    shiftOut(data, clock, LSBFIRST, one);
    delay(500);
    shiftOut(data, clock, LSBFIRST, two);
    delay(500);
    shiftOut(data, clock, LSBFIRST, three);
    delay(500);
    shiftOut(data, clock, LSBFIRST, four);
    delay(500);
    shiftOut(data, clock, LSBFIRST, five);
    delay(500);
    shiftOut(data, clock, LSBFIRST, six);
    delay(500);
    shiftOut(data, clock, LSBFIRST, seven);
    delay(500);
    shiftOut(data, clock, LSBFIRST, eight);
    delay(500);
    shiftOut(data, clock, LSBFIRST, nine);
    delay(500);
}
