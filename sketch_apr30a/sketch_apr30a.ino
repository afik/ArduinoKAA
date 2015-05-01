
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        // 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  pinMode(10,OUTPUT);
  Serial.begin(9600);   
}
 
void loop(void) {
  digitalWrite(10,HIGH);
  photocellReading = analogRead(photocellPin);  
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  analogWrite(LEDpin, LEDbrightness);
 
  Serial.print("LED = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  onOff(photocellReading);
  delay(100);
}

void onOff(int value){
  if (value < 800){
      digitalWrite(LEDpin,LOW);
  }else{
      digitalWrite(LEDpin,HIGH);     

  }
}
