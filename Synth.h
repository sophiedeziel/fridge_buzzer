#ifndef Synth_h
#define Synth_h

#include "song.h"
#include "notes.h"

class Synth {
  public:
    int tempo;
    int speakerPin;
    int switchPin;

    Synth(int pin) {
      speakerPin = pin;
      setup();
    }

    Synth(int pin1, int pin2) {
      speakerPin = pin1;
      switchPin = pin2;
      setup();
    }

    void play(Song &song) {
      int songLength = sizeof(song.beats) / sizeof(int);
      tempo = song.tempo;

      for (int i = 0; i < songLength; i++) {
        if (switchPin > 0)
        {
          int interupt = digitalRead(switchPin);

          if (interupt == 1) {
            break;
          }
        }

        if (song.notes[i] == 0) {
          delay(noteDurationInMs(song.beats[i])); // rest
        } else {
          float timePlay = noteDurationInMs(song.beats[i]);
          playTone(song.notes[i], timePlay - 50);
          delay(50);
        }
      }
    };
    
  private:

    void setup() {
      pinMode(switchPin, INPUT);
      pinMode(speakerPin, OUTPUT);
    }

    void playTone(int freq, float duration) {
      long delayValue = 1000000 / freq / 2;
      long numCycles  = freq * duration / 1000;

      for (long i = 0; i < numCycles; i++) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(delayValue);
        digitalWrite(speakerPin, LOW); // write the buzzer pin low to pull back the diaphram
        delayMicroseconds(delayValue); // wait again or the calculated delay value
      }
    }

    float noteDurationInMs(int duration) {
      return ((60.0 / (float)tempo) * (float)duration);
    }
};

#endif
