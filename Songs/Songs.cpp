





#include "Arduino.h"
#include "Songs.h"
#include "pitches.h"

int mario_melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int mario_tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

int mario_underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};

int mario_underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int zelda_melody[] = {
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,  NOTE_E4,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4,  NOTE_F4,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4,  NOTE_CS4,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_CS4, NOTE_C4,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_CS4,
  NOTE_A3, NOTE_G3, NOTE_G4, NOTE_F4, NOTE_FS4, NOTE_F4,
  NOTE_G4, NOTE_F4, NOTE_G4, NOTE_CS4, NOTE_F4, NOTE_G4,
  NOTE_F4, NOTE_CS4, NOTE_C4
};

int zelda_noteDurations[] = {
  3, 4, 4, 6, 6, 3,
  4, 6, 6, 4, 4, 3,
  2, 6, 6, 4, 6, 6,
  3, 4, 4, 6, 6, 3,
  3, 4, 4, 6, 6, 3,
  4, 6, 6, 4, 4, 3,
  4, 6, 6, 4, 6, 6,
  3, 4, 4
};

Songs::SongPin(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void SuperMario::mario()
{
  sing(1);
  sing(1);
  sing(2);
}

void sing(int s, SongPin melodyPin) {
  if (s == 2) {
    Serial.println("Underworld Theme");
    int size = sizeof(mario_underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / mario_underworld_tempo[thisNote];
      buzz(melodyPin, mario_underworld_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }
  else {
    Serial.println("Mario Theme");
    int size = sizeof(mario_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / mario_tempo[thisNote];
      buzz(melodyPin, mario_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(melodyPin, 0, noteDuration);
    }
  }
}

void SuperMario::buzz(int targetPin, long frequency, long length)
{
  digitalWrite(targetPin, HIGH);
  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(targetPin, LOW);
}

void Zelda::zelda(int targetPin)
{
  for (int thisNote = 0; thisNote < 45; thisNote++) {
    int noteDuration = 1000/zelda_noteDurations[thisNote];
    tone(_pin, zelda_melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(_pin);
  }
}
