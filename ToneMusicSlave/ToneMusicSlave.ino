#include <Wire.h>
#include <Tone.h>

#define SPEAKER_PINS { 22, 23 }
#define I2C_ADDRESS 8

int speaker_pins [] = SPEAKER_PINS;
const int speaker_count = sizeof(speaker_pins) / 2;
Tone speakers [speaker_count];

void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  for (int i = 0; i < speaker_count; i++) {
    speakers[i].begin(speaker_pins[i]);
  }
}

void loop() {}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    int speakerNumber = Wire.read() - 1;

    float note = 0.00;
    get_4byte_from_i2c ((byte*) &note);

    float dauer = 0.00;
    get_4byte_from_i2c ((byte*) &dauer);

    speakers[speakerNumber].play(note, dauer);
  }
}

void get_4byte_from_i2c(byte* wert)
{
  for (int i = 0; i < 4; i++) {
    wert[i] = Wire.read();
    Serial.println(wert[i]);
  }
}
