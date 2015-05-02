/*
Advanced Blink with an Interrupt Sketch
By: David M. Orlo
www.DaviedOrlo.com
*/
#include <Keypad.h>
#define data 3
#define clock 4
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
String readString;
byte SWITCHPIN=2;
int LEDPin=5;
byte brightness; 
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

//byte delayedoff;
//byte delayedon;

volatile boolean trigger = LOW;
int photocellPin = 0;
int photocellReading;
int LEDPin2 = 13;
int LEDbrightness;

void setup(){
	pinMode(clock, OUTPUT); // make the clock pin an output
	pinMode(data , OUTPUT); // make the data pin an output
	pinMode(5, OUTPUT);
	//digitalWrite(ledpin, HIGH);
	attachInterrupt(0, interrupttrigger, LOW); //Interrupt 0 is Digital Pin 2
	pinMode(LEDPin, OUTPUT);
	pinMode(LEDPin2,OUTPUT);
	Serial.begin(9600);  
}

void loop(){
	
	// send data only when you receive data:
	ReadInput();
	//digitalWrite(10,HIGH);
	photocellReading = analogRead(photocellPin);  

	Serial.print("Analog reading = ");
	Serial.println(photocellReading);

	// that means we have to -invert- the reading from 0-1023 back to 1023-0
	photocellReading = 1023 - photocellReading;
	//now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
	LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
	analogWrite(LEDPin, LEDbrightness);
	Serial.print("LED = ");
	Serial.println(photocellReading);     // the raw analog reading

	onOff(photocellReading);
	//delay(1000);
	
	//delay(200); //Wait a moment to help debounce the switch
	if (trigger==1){
		crazyLED();
	}
	else{
		analogWrite(LEDPin, 0);
	}
	
char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    Serial.println(key);
    switch (key)
    {
      case '1':
        analogWrite(9, 255);
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

void crazyLED(){
	//delay(200); //Wait a moment to help debounce the switch
	while(trigger == HIGH){ //Will run this loop until the interrupt value changes
		//brightness = 250; //Generates a random number from 1-254 and assigns it to the variable named brightness
		//delayedoff = random(1, 125); //A random amount of time the LED is turned off
		//delayedon = random(1, 250); //A random amount of time the LED is turned on
		analogWrite(LEDPin, brightness); //Uses the random number we generated to write the value to our LED
		delay(10); //random delay on time
		analogWrite(LEDPin, 0); //We turn the LED off for a blinking effect
		delay(100);
	} //Random delay off time
}

void interrupttrigger(){
	if (trigger ==LOW){
		trigger=HIGH;
	}
	else{
		trigger=LOW;
	}
}
void onOff(int value){
  if (value < 800){
      digitalWrite(LEDPin2,LOW);
  }else{
      digitalWrite(LEDPin2,HIGH);     

  }
}
void ReadInput(){
	while (Serial.available()) {
		delay(3);  
		char c = Serial.read();
		readString += c; 
	}
	checkCommand(readString);
}
void checkCommand(String input){
	readString.trim();
	if (readString.length() >0) {
		if(readString == "ON"){
			analogWrite(2,HIGH);
			Serial.println(readString);
		}
		if(readString == "OFF"){
			analogWrite(2,LOW);
			Serial.println(readString);
		}
		Serial.println(readString);
	}
	readString = "";
}
