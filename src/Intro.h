#ifndef INTRO_H
#define INTRO_H

#include "GameState.h"

#include <allegro.h>
#include <loadpng.h>
#include <string>
#include <vector>

#include "globals.h"
#include "tools.h"

// Intro screen of game
class Intro : public GameState {
 private:
  // Intro background
  BITMAP* intro[2];

 public:
  // Main loop functions
  Intro();
  void update();
  void draw(bool toScreen);
  ~Intro();
};

#endif  // INTRO_H
