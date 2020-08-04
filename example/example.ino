#include "myMelody.h"
#include <ToneMusic.h>

#define BPM 100

ToneMusic tone1;
ToneMusic tone2;

float melody1 [] = MELODY1;
float melody2 [] = MELODY2;

void setup() {
  Wire.begin(); 

  //Serial.begin(9600);

  tone1.attachI2C(8, 1);
  tone2.attachI2C(8, 2);
  
  tone1.writeMelody(melody1, sizeof(melody1), BPM);
  tone2.writeMelody(melody2, sizeof(melody2), BPM);

}


void loop() {
  tone1.play();
  tone2.play();
}
