# Arduino-ToneMusic

## Summary

Small arduino library supposed to simplify the creation of melodies with the [Arduino Tone-Library](https://github.com/daniel-centore/arduino-tone-library). Beyond the hardware-specific maximum number of speakers, an unlimited number of additional speakers can be connected via the I2C bus by using the [ToneMusicSlave](https://github.com/jayAitch256/Arduino-ToneMusic/blob/master/ToneMusicSlave/)-Sketch.

Melodies are defined as macro arrays, "written" on the Arduino by calling `writeMelody()` and played by running the `play()` function in a loop. If you want to use multiple speakers, you can just write multiple melodies and play them simultaneously.


## Example Sketch

An example sketch on how to use the library can be found [here](https://github.com/jayAitch256/Arduino-ToneMusic/blob/master/ToneMusicExample/).


## Defining a melody

Melodies have to be defined in the following way:

```
#define MELODY { \
duration, frequency, legato, \  //Note 1
duration, frequency, legato, \  //Note 2
[...]
}
```

`duration`  

 - "Value" of the note as a part of 1 (e.g. quarter note = 4)


`frequency` 

 - Frequency of the note in Hz. 
 - The library has some notes predefined (just have a look at the [ToneMusic.h](https://github.com/jayAitch256/Arduino-ToneMusic/blob/master/ToneMusic/ToneMusic.h)-file), so you can just use them.


`legato`

 - 0 = just a normal note, with a small break at the end
 - 1 = the following note will be directly "connected" to this note


## Functions

A `ToneMusic`-object offers the following methods:

**`attachPin(pin)`**
 - _Attaches the ToneMusic-object to a speaker connected to a specific PWM-pin of the Arduino_
 - **Parameters:** Number of pin (`int`)


**`attachI2C(address, number)`**
 - _Attaches the ToneMusic-object to a speaker connected to a different Arduino, which is connected via the I2C-Bus. The slave-Arduino has to be configured using the [ToneMusicSlave](https://github.com/jayAitch256/Arduino-ToneMusic/blob/master/ToneMusicSlave/)-Sketch_
 - **Parameters:** I2C Address of slave (`int`), number of speaker (`int`)


**`writeMelody(melody, sizeof(melody), bpm)`**
 - _Writes a previously defined melody to local storage. Has to be called before you can play the melody._
 - **Parameters:** Melody-array (`float []`), size of array (`int`), Beats per Minute (`int`)


**`play()`**
 - _Plays the melody_
 - **Be cautious: Simply calling this function once will not work. It has to be run in a loop.**
