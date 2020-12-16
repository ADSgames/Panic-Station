#ifndef MENU_H
#define MENU_H

#include "GameState.h"

#include <allegro.h>
#include <loadpng.h>
#include <string>
#include <vector>

#include <logg.h>

#include "globals.h"
#include "tileMap.h"
#include "tools.h"

class Menu : public GameState {
 private:
  // Menu/GUI
  BITMAP *buffer, *levelSelectLeft, *levelSelectRight, *levelSelectNumber,
      *cursor[2], *menuselect, *menu, *menu_edit, *help;
  SAMPLE* click;
  SAMPLE* music;

  // Live background
  int animationFrame;
  tileMap* tile_map;
  string scrollDirection;

  // Menu
  int selectorY, selectorX, newSelectorY, selected_object;
  int cursor_x, cursor_y;
  int menu_view_x, menu_view_y;
  bool menuOpen, editMode;

 protected:
 public:
  // Main loop functions
  Menu();
  void update();
  void draw(bool toScreen);
  ~Menu();
};

#endif  // MENU_H
