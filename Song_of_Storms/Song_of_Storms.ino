/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_D4,NOTE_F4,NOTE_D5,
  NOTE_D4,NOTE_F4,NOTE_D5,
  NOTE_E5,NOTE_F5,NOTE_E5,NOTE_F5,
  NOTE_E5,NOTE_C5,NOTE_A4,
  NOTE_A4,NOTE_D4,NOTE_F4,NOTE_G4,
  NOTE_A4,
  NOTE_A4,NOTE_D4,NOTE_F4,NOTE_G4,
  NOTE_E4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,8,2,
  8,8,2,
  3,8,8,8,
  8,8,2,
  4,4,8,8,
  2,
  4,4,8,8,
  2
};

const int buttonPin = 12;
bool play = false; 
int buttonState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(play);
  Serial.println(buttonState);
  if(buttonState == HIGH){
    play = true;
  }
  if(play){
    playMusic();
  }
  delay(250);
}

void playMusic(){
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 23; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    //   i.e. tone(pin, frequency, duration)
    tone(8, melody[thisNote],noteDuration);
    Serial.println("Pin:8  Note: " + String(thisNote) + " Note Duration: " + String(noteDuration));
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  play = false;
}
