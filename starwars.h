#ifndef StarWars_h
#define StarWars_h
#include "song.h"

class StarWars : public Song 
{
  public:
    int notes[18] = {
      NOTE_A2, NOTE_A2, NOTE_A2,
      NOTE_F2, NOTE_CS3, NOTE_A2,
      NOTE_F2, NOTE_CS3, NOTE_A2,

      NOTE_E3, NOTE_E3, NOTE_E3,
      NOTE_F3, NOTE_CS3, NOTE_GS2,
      NOTE_F2, NOTE_CS3, NOTE_A2,
    };
    int beats[18] = {
      1000, 1000, 1000,
      750, 250, 1000,
      750, 250, 2000,

      1000, 1000, 1000,
      750, 250, 1000,
      750, 250, 2000
    };
    int tempo = 108;
};

#endif
