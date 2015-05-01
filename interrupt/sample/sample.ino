/*
Advanced Blink with an Interrupt Sketch
By: David M. Orlo
www.DaviedOrlo.com
*/
String readString;
byte SWITCHPIN=2;
int LEDPin=6;
byte brightness; 
//byte delayedoff;
//byte delayedon;

volatile boolean trigger = LOW;
int photocellPin = 0;
int photocellReading;
int LEDPin2 = 11;
int LEDbrightness;

void setup(){
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
	delay(1000);
	
	//delay(200); //Wait a moment to help debounce the switch
	if (trigger==1){
		crazyLED();
	}
	else{
		analogWrite(LEDPin, 0);
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