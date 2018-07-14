#ifndef Zelda_h
#define Zelda_h
#include "song.h"

class Zelda : public Song
{
  public:
    int notes[21] = {
      NOTE_B4, NOTE_CS5, NOTE_DS5, NOTE_F5,
      NOTE_C5, NOTE_D5, NOTE_E5, NOTE_FS5,
      NOTE_CS5, NOTE_DS5, NOTE_F5, NOTE_G5,
      NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_GS5,
      0,
      NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5,
    };
    int beats[21] = {
      250, 250, 250, 250,
      250, 250, 250, 250,
      250, 250, 250, 250,
      250, 250, 250, 250,
      1000,
      500, 500, 500, 4000,
    };
    int tempo = 120;
};

#endif
