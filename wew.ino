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

/* PUNYA AHMAD */
int speakerPin = 10;

// FUR ELISE
char notesF[] = "EDEDEbDCaceabegbCeEDEDEbDCaceabeCbaEDEDEbDCaceabegbCeEDEDEbDCaceabeCbabCDEgFEDfEDCeDCbeEeEDEDEDEDEDEDEbDCaceabegbCeEDEDEbDCaceabeCba"; 
int beatsF[] = { 1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,3,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,6};
int tempoF = 175;

// TWINKLE
char notesT[] = "ccggaagffeeddc "; // a space represents a rest
int beatsT[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempoT = 300;

// Lullaby song
char notesL[] = "eegeegegcbaagdefddefdfbagbcccafgecfgaegccafgecfgfedc";
int beatsL[] = { 1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,3,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,6};
int tempoL = 300;


void setup(){
	pinMode(clock, OUTPUT); // make the clock pin an output
	pinMode(data , OUTPUT); // make the data pin an output
	pinMode(5, OUTPUT);
	//digitalWrite(ledpin, HIGH);
	attachInterrupt(0, interrupttrigger, LOW); //Interrupt 0 is Digital Pin 2
	pinMode(LEDPin, OUTPUT);
	pinMode(LEDPin2,OUTPUT);
        pinMode(speakerPin, OUTPUT);
	Serial.begin(9600);  
}

int mode = 0;
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
        mode = 3;
        break;
      case '4':
        shiftOut(data, clock, LSBFIRST, four);
        mode = 4;
        break;
      case '5':
        shiftOut(data, clock, LSBFIRST, five);
        break;
      case '6':
        shiftOut(data, clock, LSBFIRST, six);
        mode = 6;
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
  
      Serial.print("Mode :"); Serial.println(mode);
      switch(mode){
        case 3 : playF();
                 break;
        case 4 : playL();
                 break;
        case 6 : playT();
                 break;          
       }    
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


/* FUNGSI AHMAD */
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'c','d','e','f','g','a','b','C', 'D', 'E', 'F', 'G', 'A', 'B', 'U', 'R'};
  int tones[] = {3822,3424,3033,2864,2551,2272,2024, 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 0};
  

// play the tone corresponding to the note name
  for (int i = 0; i < sizeof(tones); i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void playF(){
  for (int i = 0; i < sizeof(notesF); i++) {
        Serial.println("loop");
        if (notesF[i] == ' ') {
          delay(beatsF[i] * tempoF); // rest
        } else {
          playNote(notesF[i], beatsF[i] * tempoF);
        }
        // pause between notes
        delay(tempoF / 2); 
        if (i == sizeof(notesF)-1){
          delay(1000);
        }
  }
}

void playT(){
  for (int i = 0; i < sizeof(notesT); i++) {
        if (notesT[i] == ' ') {
          delay(beatsT[i] * tempoT); // rest
        } else {
          playNote(notesT[i], beatsT[i] * tempoT);
        }
        // pause between notes
        delay(tempoT / 2); 
        if (i == sizeof(notesT)-1){
          delay(1000);
        }
  }
}

void playL(){
   for (int i = 0; i < sizeof(notesL); i++) {
        if (notesL[i] == ' ') {
          delay(beatsL[i] * tempoL); // rest
        } else {
          playNote(notesL[i], beatsL[i] * tempoL);
        }

        // pause between notes
        delay(tempoL / 2); 
        if (i == sizeof(notesL)-1){
          delay(1000);
        }
  }
}
