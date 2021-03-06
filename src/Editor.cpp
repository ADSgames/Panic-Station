#include "Editor.h"

Editor::Editor() {
  layer = 1;

  // Other Sprites
  buffer = create_bitmap(1280, 960);

  // Create map
  tile_map = new tileMap("data/templates/blank64x48");

  // Create example tile
  exampleTile = new tile(0);
  exampleTile->setX(0);
  exampleTile->setY(0);
  exampleTile->setType(0);

  FONT *f1, *f2, *f3, *f4, *f5;

  // Sets Font
  if (!(f1 = load_font("fonts/pixelart_2.pcx", NULL, NULL))) {
    abort_on_error(
        "Cannot find fonts/pixelart_2.pcx \n Please check your files and try "
        "again");
  }
  f2 = extract_font_range(f1, ' ', 'A' - 1);
  f3 = extract_font_range(f1, 'A', 'Z');
  f4 = extract_font_range(f1, 'Z' + 1, 'z');

  // Merge fonts
  font = merge_fonts(f4, f5 = merge_fonts(f2, f3));

  // Destroy temporary fonts
  destroy_font(f1);
  destroy_font(f2);
  destroy_font(f3);
  destroy_font(f4);
  destroy_font(f5);

  edittext = ".txt";
  iter = edittext.begin();

  opening = false;
  saving = false;

  draw(false);
  highcolor_fade_in(buffer, 16);

  set_alpha_blender();
}

void Editor::init() {}

void Editor::save() {
  // Name input
  if (keypressed()) {
    int newkey = readkey();
    char ASCII = newkey & 0xff;
    char scancode = newkey >> 8;

    // a character key was pressed; add it to the string
    if (ASCII >= 32 && ASCII <= 126 && edittext.length() < 25 &&
        scancode != KEY_SPACE) {
      // add the new char
      iter = edittext.insert(iter, ASCII);
      // increment both the caret and the iterator
      iter++;
    }
    // some other, "special" key was pressed; handle it here
    else {
      if (scancode == KEY_DEL) {
        if (iter != edittext.end()) {
          iter = edittext.erase(iter);
        }
      }
      if (scancode == KEY_BACKSPACE) {
        if (iter != edittext.begin()) {
          iter--;
          iter = edittext.erase(iter);
        }
      }
      if (scancode == KEY_RIGHT) {
        if (iter != edittext.end()) {
          iter++;
        }
      }
      if (scancode == KEY_LEFT) {
        if (iter != edittext.begin()) {
          iter--;
        }
      }
      if (scancode == KEY_ENTER) {
        // Save fronts
        int widthCounter;
        string finalFile = "data/" + edittext;
        ofstream saveRaw1;
        saveRaw1.open(finalFile.c_str());

        widthCounter = 0;
        for (unsigned int i = 0; i < tile_map->mapTiles.size(); i++) {
          widthCounter++;
          if (widthCounter == tile_map->width) {
            saveRaw1 << tile_map->mapTiles.at(i).getType() << "\n";
            widthCounter = 0;
          } else {
            saveRaw1 << tile_map->mapTiles.at(i).getType() << " ";
          }
        }
        saveRaw1.close();

        // Save backs
        finalFile =
            "data/" + edittext.substr(0, edittext.size() - 4) + "_back.txt";
        ofstream saveRaw2;
        saveRaw2.open(finalFile.c_str());

        widthCounter = 0;
        for (unsigned int i = 0; i < tile_map->mapTilesBack.size(); i++) {
          widthCounter++;
          if (widthCounter == tile_map->width) {
            saveRaw2 << tile_map->mapTilesBack.at(i).getType() << "\n";
            widthCounter = 0;
          } else {
            saveRaw2 << tile_map->mapTilesBack.at(i).getType() << " ";
          }
        }
        saveRaw2.close();
        saving = false;
      }
    }
  }
}

void Editor::open() {
  tile_map->mapTiles.clear();
  tile_map->mapTilesBack.clear();

  // Name input
  if (keypressed()) {
    int newkey = readkey();
    char ASCII = newkey & 0xff;
    char scancode = newkey >> 8;

    // a character key was pressed; add it to the string
    if (ASCII >= 32 && ASCII <= 126 && edittext.length() < 25 &&
        scancode != KEY_SPACE) {
      // add the new char
      iter = edittext.insert(iter, ASCII);
      // increment both the caret and the iterator
      iter++;
    }
    // some other, "special" key was pressed; handle it here
    else {
      if (scancode == KEY_DEL) {
        if (iter != edittext.end()) {
          iter = edittext.erase(iter);
        }
      }
      if (scancode == KEY_BACKSPACE) {
        if (iter != edittext.begin()) {
          iter--;
          iter = edittext.erase(iter);
        }
      }
      if (scancode == KEY_RIGHT) {
        if (iter != edittext.end()) {
          iter++;
        }
      }
      if (scancode == KEY_LEFT) {
        if (iter != edittext.begin()) {
          iter--;
        }
      }
      if (scancode == KEY_ENTER) {
        string finalFile = "data/" + edittext.substr(0, edittext.size() - 4);
        tile_map->load(finalFile);
        opening = false;
      }
    }
  }
}

void Editor::update() {
  // Back to menu
  if (key[KEY_M]) {
    set_next_state(STATE_MENU);
  }

  if (saving) {
    save();
  } else if (opening) {
    open();
  } else {
    // Scroll Map
    if (mouse_y * resDiv < 10 && tile_map->y > 0) {
      tile_map->y -= 16;
    }
    if (mouse_y * resDiv > 950 && tile_map->y < tile_map->height * 64 - 960) {
      tile_map->y += 16;
    }
    if (mouse_x * resDiv < 10 && tile_map->x > 0) {
      tile_map->x -= 8;
    }
    if (mouse_x * resDiv > 1270 && tile_map->x < tile_map->width * 64 - 1280) {
      tile_map->x += 8;
    }

    // Change selected
    if (key[KEY_UP]) {
      if (exampleTile->getType() < 500) {
        do {
          exampleTile->setType(exampleTile->getType() + 1);
          selectedTileType = exampleTile->getType();
        } while (exampleTile->getImage() == NULL &&
                 exampleTile->getType() < 400);
        rest(100);
      }
    }
    if (key[KEY_DOWN]) {
      if (exampleTile->getType() > 1) {
        do {
          exampleTile->setType(exampleTile->getType() - 1);
          selectedTileType = exampleTile->getType();
        } while (exampleTile->getImage() == NULL && exampleTile->getType() > 1);
        rest(100);
      }
    }

    // Change Layer
    if (key[KEY_TAB]) {
      if (layer == 0) {
        layer = 1;
      } else {
        layer = 0;
      }
      while (key[KEY_TAB]) {
      }
    }

    // Place tile
    if (mouse_b & 1) {
      // Check for collision
      if (layer == 1) {
        for (unsigned int i = 0; i < tile_map->mapTiles.size(); i++) {
          if (collisionAny(mouse_x + tile_map->x, mouse_x + tile_map->x,
                           tile_map->mapTiles.at(i).getX(),
                           tile_map->mapTiles.at(i).getX() +
                               tile_map->mapTiles.at(i).getWidth(),
                           mouse_y + tile_map->y, mouse_y + tile_map->y,
                           tile_map->mapTiles.at(i).getY(),
                           tile_map->mapTiles.at(i).getY() +
                               tile_map->mapTiles.at(i).getHeight())) {
            tile_map->mapTiles.at(i).setType(selectedTileType);
          }
        }
      } else {
        for (unsigned int i = 0; i < tile_map->mapTilesBack.size(); i++) {
          if (collisionAny(mouse_x + tile_map->x, mouse_x + tile_map->x,
                           tile_map->mapTilesBack.at(i).getX(),
                           tile_map->mapTilesBack.at(i).getX() + 64,
                           mouse_y + tile_map->y, mouse_y + tile_map->y,
                           tile_map->mapTilesBack.at(i).getY(),
                           tile_map->mapTilesBack.at(i).getY() + 64)) {
            tile_map->mapTilesBack.at(i).setType(selectedTileType);
          }
        }
      }
    }

    // Erase tile
    if (mouse_b & 2) {
      // Check for collision
      if (layer == 1) {
        for (unsigned int i = 0; i < tile_map->mapTiles.size(); i++) {
          if (collisionAny(mouse_x + tile_map->x, mouse_x + tile_map->x,
                           tile_map->mapTiles.at(i).getX(),
                           tile_map->mapTiles.at(i).getX() +
                               tile_map->mapTiles.at(i).getWidth(),
                           mouse_y + tile_map->y, mouse_y + tile_map->y,
                           tile_map->mapTiles.at(i).getY(),
                           tile_map->mapTiles.at(i).getY() +
                               tile_map->mapTiles.at(i).getHeight())) {
            tile_map->mapTiles.at(i).setType(0);
          }
        }
      } else {
        for (unsigned int i = 0; i < tile_map->mapTilesBack.size(); i++) {
          if (collisionAny(mouse_x + tile_map->x, mouse_x + tile_map->x,
                           tile_map->mapTilesBack.at(i).getX(),
                           tile_map->mapTilesBack.at(i).getX() + 64,
                           mouse_y + tile_map->y, mouse_y + tile_map->y,
                           tile_map->mapTilesBack.at(i).getY(),
                           tile_map->mapTilesBack.at(i).getY() + 64)) {
            tile_map->mapTilesBack.at(i).setType(0);
          }
        }
      }
    }
    if (key[KEY_K]) {
      // Check for collision
      if (layer == 1) {
        for (unsigned int i = 0; i < tile_map->mapTiles.size(); i++) {
          if (collisionAny(mouseX() + tile_map->x, mouseX() + tile_map->x,
                           tile_map->mapTiles.at(i).getX(),
                           tile_map->mapTiles.at(i).getX() + 64,
                           mouseY() + tile_map->y, mouseY() + tile_map->y,
                           tile_map->mapTiles.at(i).getY(),
                           tile_map->mapTiles.at(i).getY() + 64)) {
            exampleTile->setX(0);
            exampleTile->setY(0);
            selectedTileType = tile_map->mapTiles.at(i).getType();
            exampleTile->setType(selectedTileType);
          }
        }
      } else {
        for (unsigned int i = 0; i < tile_map->mapTilesBack.size(); i++) {
          if (collisionAny(mouseX() + tile_map->x, mouseX() + tile_map->x,
                           tile_map->mapTilesBack.at(i).getX(),
                           tile_map->mapTilesBack.at(i).getX() + 64,
                           mouseY() + tile_map->y, mouseY() + tile_map->y,
                           tile_map->mapTilesBack.at(i).getY(),
                           tile_map->mapTilesBack.at(i).getY() + 64)) {
            exampleTile->setX(0);
            exampleTile->setY(0);
            selectedTileType = tile_map->mapTilesBack.at(i).getType();
            exampleTile->setType(selectedTileType);
          }
        }
      }
    }
    // Save map
    if (key[KEY_S]) {
      saving = true;
    }

    // Open map
    if (key[KEY_O]) {
      opening = true;
    }

    // Fill map
    if (key[KEY_F]) {
      for (unsigned int i = 0; i < tile_map->mapTilesBack.size(); i++) {
        tile_map->mapTilesBack.at(i).setType(selectedTileType);
      }
    }
    if (key[KEY_G]) {
      for (unsigned int i = 0; i < tile_map->mapTiles.size(); i++) {
        tile_map->mapTiles.at(i).setType(selectedTileType);
      }
    }
  }
}

void Editor::draw(bool toScreen) {
  // Background
  rectfill(buffer, 0, 0, 1280, 960, makecol(255, 255, 255));

  if (saving) {
    // Create gui
    textprintf_centre_ex(buffer, font, 640, 310, makecol(0, 0, 0), -1,
                         "Save Map Name");

    // Input rectangle
    rectfill(buffer, 400, 408, 892, 452, makecol(0, 0, 0));
    rectfill(buffer, 402, 410, 890, 450, makecol(255, 255, 255));

    // Output the string to the screen
    textout_ex(buffer, font, edittext.c_str(), 410, 410, makecol(0, 0, 0), -1);

    // Draw the caret
    vline(buffer,
          text_length(font, edittext.c_str()) + 410 - text_length(font, ".txt"),
          412, 448, makecol(0, 0, 0));
  } else if (opening) {
    // Create gui
    textprintf_centre_ex(buffer, font, 640, 310, makecol(0, 0, 0), -1,
                         "Open Map Name");

    // Input rectangle
    rectfill(buffer, 400, 408, 892, 452, makecol(0, 0, 0));
    rectfill(buffer, 402, 410, 890, 450, makecol(255, 255, 255));

    // Output the string to the screen
    textout_ex(buffer, font, edittext.c_str(), 410, 410, makecol(0, 0, 0), -1);

    // Draw the caret
    vline(buffer,
          text_length(font, edittext.c_str()) + 410 - text_length(font, ".txt"),
          412, 448, makecol(0, 0, 0));
  } else {
    // Draw tiles
    tile_map->draw_map(buffer);
    exampleTile->draw_tile(buffer, 0, 0, 0);

    // Map info
    textprintf_ex(buffer, font, 0, 100, makecol(0, 0, 0), -1,
                  "height-%i width-%i", tile_map->height, tile_map->width);

    if (layer == 1) {
      textprintf_ex(buffer, font, 0, 150, makecol(0, 255, 0), -1,
                    "Editing Mode: Foreground");
    } else if (layer == 0) {
      textprintf_ex(buffer, font, 0, 150, makecol(255, 0, 0), -1,
                    "Editing Mode: Background");
    }

    // Cursor
    circlefill(buffer, mouse_x * resDiv, mouse_y * resDiv, 10,
               makecol(0, 0, 0));
    circlefill(buffer, mouse_x * resDiv, mouse_y * resDiv, 8,
               makecol(255, 255, 255));
  }

  // Draw buffer
  if (toScreen) {
    stretch_sprite(screen, buffer, 0, 0, SCREEN_W, SCREEN_H);
  }
}

Editor::~Editor() {
  destroy_bitmap(buffer);

  delete tile_map;
  delete exampleTile;

  // Fade out
  highcolor_fade_out(16);
}
