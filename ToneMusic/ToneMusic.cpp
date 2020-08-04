#include "Arduino.h"
#include "ToneMusic.h"


ToneMusic::ToneMusic()
{
  _resumeMillis = 0;
  _currentIndex = 0;
  _melodySize = 0;
}

void ToneMusic::attachPin(int pin)
{
  _remote = false;
  _localSpeaker.begin(pin);
}

void ToneMusic::attachI2C(int address, int number)
  {
  _remote = true;
  _I2CAddress = address;
  _I2CNumber = number;
}

void ToneMusic::writeMelody (float melody [], int arraySize, int bpm)
{
  _bpm = bpm;
  _melodySize = arraySize / 4;
  //Serial.print("Writing melody of size ");
  //Serial.println(_melodySize);
  _melody = new float[_melodySize];

  for (int i = 0; i < _melodySize; i = i + 3) {
    melody[i] = (float) ((60000.0 * 4.0) / (_bpm * melody[i]));
    if (melody[i + 2] != LEGATO) melody[i] = melody[i] - 200.0;

    _melody[i] = melody[i];
    _melody[i +1] = melody[i +1];
    _melody[i +2] = melody[i +2];
  }
}


void ToneMusic::play ()
{
  if (millis() >= _resumeMillis) {
    
    if (_currentIndex + 2 < _melodySize) {
      float dauer = _melody[_currentIndex];
      float note = _melody[_currentIndex + 1];

      if (_remote) {
        Wire.beginTransmission(_I2CAddress);
        Wire.write(_I2CNumber);
        put_4byte_to_i2c((byte *)&note);
        put_4byte_to_i2c((byte *)&dauer);
        Wire.endTransmission();
        }
      else {
        _localSpeaker.play(note, dauer);
      }

      if (_melody[_currentIndex + 2] != LEGATO) _resumeMillis = millis() + dauer + 200;
      else _resumeMillis = millis() + dauer;

      _currentIndex =  _currentIndex + 3;
    }

    else  _currentIndex = 0;
  }
}

void ToneMusic::put_4byte_to_i2c(byte* value)
  {
  for (int i = 0; i < 4; i++) Wire.write(value[i]);
  }
