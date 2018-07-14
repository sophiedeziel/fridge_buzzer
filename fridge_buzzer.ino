#include "Synth.h"
#include "zelda.h"
#include "starwars.h"

const int speakerPin = 11;
const int switchPin = 12;
int ontherPin;

int tempo = 75;
bool played = false;

Synth keyboard(speakerPin);
Zelda zelda;
StarWars sw;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(switchPin) == 1) {
    reset();
  }

  if (digitalRead(switchPin) == 0 && played == false) {
    int randomizer = random(100);
    played = true;

    Serial.println(randomizer);
    if (randomizer <= 10) {
      playZelda();
    } else if (randomizer == 42) {
      playStarWars();
    }
  }
  delay(100);
}

void reset() {
  played = false;
}

void playZelda() {
  Serial.println("play zelda");
  keyboard.play(zelda);
  Serial.println("Song Finished");
}

void playStarWars() {
  Serial.println("play star wars");
  keyboard.play(sw);
  Serial.println("Song Finished");
}


