#ifndef GAME_H
#define GAME_H

#include "GameState.h"

#include <allegro.h>
#include <loadpng.h>
#include <string>
#include <vector>

#include <logg.h>

#include "globals.h"
#include "tools.h"

#include "enemy.h"
#include "player.h"
#include "tileMap.h"

using namespace std;

// Main game screen
class Game : public GameState {
 private:
  BITMAP* buffer;

  // Variables
  int animationFrame;

  // Objects
  player character;
  vector<enemy*> badGuy;

  tileMap* tile_map;
  tileMap* newTileMap;

 public:
  // Main loop functions
  Game();
  void init();
  void update();
  void draw(bool toScreen);
  ~Game();
};

#endif
