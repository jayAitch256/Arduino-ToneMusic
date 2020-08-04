#ifndef ToneMusic_h
#define ToneMusic_h

#include "Arduino.h"
#include <Wire.h>
#include <Tone.h>

#define pause 0.000000

#define h4  3951.066 
#define b4 3729.310 
#define a4 3520.0000  
#define as4 3322.438 
#define g4 3135.963 
#define ges4 2959.955 
#define f4 2793.826 
#define e4 2637.02 
#define es4 2489.016 
#define d4 2349.318 
#define des4 2217.461 
#define c4 2093.005 

#define h3 1975.533 
#define b3 1864.655 
#define a3 1760.000  
#define as3 1661.219 
#define g3 1567.982 
#define ges3 1479.978 
#define f3 1396.913 
#define e3 1318.510 
#define es3 1244.508 
#define d3 1174.659 
#define des3 1108.731 
#define c3 1046.502 

#define h2 987.7666 
#define b2 932.32
#define a2 880.0000
#define as2 830.6094 
#define g2 783.9909 
#define ges2 739.9888 
#define f2 698.4565 
#define e2 659.2551 
#define es2 622.2540 
#define d2 587.3295 
#define des2 554.3653 
#define c2 523.2511 

#define h1 493.8833 
#define b1 466.1638 
#define a1 440.0000  
#define as1 415.3047 
#define g1 391.9954 
#define ges1 369.9944 
#define f1 349.2282 
#define e1 329.6276 
#define es1 311.1270 
#define d1 293.6648 
#define des1 277.1826 
#define c1 261.6256 

#define h 246.9417 
#define b 233.0819 
#define a 220.0000  
#define as 207.6523 
#define g 195.9977 
#define ges 184.9972 
#define f 174.6141 
#define e 164.8138 
#define es 155.5635 
#define d 146.8324 
#define des 138.5913 
#define c 130.8128 

#define H 123.4708 
#define B 116.5409 
#define A 110.0000  
#define As 103.8262 
#define G 97.99886 
#define Ges 92.49861 
#define F 87.30706 
#define E 82.40689 
#define Es 77.78175 
#define D 73.41619 
#define Des 69.29566 
#define C 65.40639 

#define LEGATO 1
#define NORMAL 0

#define BPM 60

#define GANZE 1
#define HALBE 2
#define VIERTEL 4
#define ACHTEL 8
#define SECHZEHNTEL 16
#define ZWEIUNDDREISSIGSTEL 32


class ToneMusic
{
  public:
    ToneMusic();
    void attachPin(int pin);
    void attachI2C(int address, int number); 
    void writeMelody(float melody [], int arraySize, int bpm); 
    void play();
  
  private:
    void put_4byte_to_i2c(byte* wert);
    boolean _remote;
    unsigned long _resumeMillis;
    int _currentIndex;
    int _I2CAddress;
    int _I2CNumber;
    int _bpm;
    int _melodySize;
    Tone _localSpeaker;
    float *_melody;
};

#endif
