
int speakerPin = 9;

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

void setup() {
  pinMode(speakerPin, OUTPUT);
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


int iterate = 0;
void loop() {
  // MODE get from MatrixKeyboard
  int mode = 2;
   
  if(mode == 1){  
    playF();    
  }
  else{
    if(mode == 2){
      playT();
    }
    else{
      if(mode == 3){
        playL();
      }
    }
  }
  Serial.println("masuk");
  playF();
  playF();
}
