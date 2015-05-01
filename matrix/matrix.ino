void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value1 = digitalRead(1);
  int value2 = digitalRead(2);
  int value3 = digitalRead(3);
  int value4 = digitalRead(4);
  int value5 = digitalRead(5);
  int value6 = digitalRead(6);
  int value7 = digitalRead(7);
  
  Serial.println(value7);
  
  delay(100);
}
