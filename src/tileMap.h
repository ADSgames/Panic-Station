#ifndef TILEMAP_H
#define TILEMAP_H

#define FRAME_MILASECONDS 100

#include <allegro.h>
#include <loadpng.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include <logg.h>

#include "globals.h"
#include "tools.h"

#include "tile.h"

using namespace std;

class tileMap{
  public:
    tileMap(string fileName);
    ~tileMap();

    vector<tile> mapTiles;
    vector<tile> mapTilesBack;

    int x;
    int y;

    int width;
    int height;

    void load_images();
    void reload( bool instant);
    void draw_map(BITMAP* tempSprite);
    void load(string fileName);

  private:
    string mapName;

    static volatile long frame;
    static void change_frame();
};

#endif
