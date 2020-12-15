#include "tileMap.h"

volatile long tileMap::frame = 0;

tileMap::tileMap(string fileName) {
  x = 0;
  y = 0;

  width = 0;
  height = 0;

  LOCK_VARIABLE(frame);
  LOCK_FUNCTION(change_frame);
  install_int_ex(change_frame, MSEC_TO_TIMER(FRAME_MILASECONDS));

  load_images();
  load(fileName);
}

void tileMap::load_images() {
  // Tile Sprites
  // Not animated
  tileSprites[tile_air][0] = load_png("images/blocks/air.png", NULL);
  tileSprites[tile_medpack][0] = load_png("images/blocks/medpack.png", NULL);
  tileSprites[tile_sky_1][0] = load_png("images/blocks/sky_1.png", NULL);
  tileSprites[tile_grass_1][0] = load_png("images/blocks/grass_1.png", NULL);
  tileSprites[tile_tallgrass_1][0] =
      load_png("images/blocks/tallgrass_1.png", NULL);
  tileSprites[tile_mailbox_1][0] =
      load_png("images/blocks/mailbox_1.png", NULL);
  tileSprites[tile_mailbox_2][0] =
      load_png("images/blocks/mailbox_2.png", NULL);
  tileSprites[tile_cloud_1][0] = load_png("images/blocks/cloud_1.png", NULL);
  tileSprites[tile_asphalt_grass][0] =
      load_png("images/blocks/asphalt_grass.png", NULL);
  tileSprites[tile_asdf][0] = load_png("images/blocks/asdf.png", NULL);

  tileSprites[tile_cement_1][0] = load_png("images/blocks/cement_1.png", NULL);
  tileSprites[tile_cement_2][0] = load_png("images/blocks/cement_2.png", NULL);
  tileSprites[tile_cement_3][0] = load_png("images/blocks/cement_3.png", NULL);
  tileSprites[tile_cement_4][0] = load_png("images/blocks/cement_4.png", NULL);
  tileSprites[tile_cement_5][0] = load_png("images/blocks/cement_5.png", NULL);
  tileSprites[tile_cement_6][0] = load_png("images/blocks/cement_6.png", NULL);
  tileSprites[tile_cement_7][0] = load_png("images/blocks/cement_7.png", NULL);
  tileSprites[tile_cement_8][0] = load_png("images/blocks/cement_8.png", NULL);
  tileSprites[tile_cement_9][0] = load_png("images/blocks/cement_9.png", NULL);

  tileSprites[tile_pipe_1][0] = load_png("images/blocks/pipe_1.png", NULL);
  tileSprites[tile_pipe_2][0] = load_png("images/blocks/pipe_2.png", NULL);
  tileSprites[tile_pipe_3][0] = load_png("images/blocks/pipe_3.png", NULL);
  tileSprites[tile_pipe_4][0] = load_png("images/blocks/pipe_4.png", NULL);
  tileSprites[tile_pipe_5][0] = load_png("images/blocks/pipe_5.png", NULL);
  tileSprites[tile_pipe_6][0] = load_png("images/blocks/pipe_6.png", NULL);
  tileSprites[tile_pipe_7][0] = load_png("images/blocks/pipe_7.png", NULL);

  tileSprites[tile_pipe_8][0] = load_png("images/blocks/pipe_8_1.png", NULL);
  tileSprites[tile_pipe_8][1] = load_png("images/blocks/pipe_8_2.png", NULL);
  tileSprites[tile_pipe_8][2] = load_png("images/blocks/pipe_8_3.png", NULL);
  tileSprites[tile_pipe_8][3] = load_png("images/blocks/pipe_8_4.png", NULL);

  tileSprites[tile_pipe_9][0] = load_png("images/blocks/pipe_9_1.png", NULL);
  tileSprites[tile_pipe_9][1] = load_png("images/blocks/pipe_9_2.png", NULL);
  tileSprites[tile_pipe_9][2] = load_png("images/blocks/pipe_9_3.png", NULL);
  tileSprites[tile_pipe_9][3] = load_png("images/blocks/pipe_9_4.png", NULL);

  tileSprites[tile_pipe_10][0] = load_png("images/blocks/pipe_10.png", NULL);
  tileSprites[tile_pipe_11][0] = load_png("images/blocks/pipe_11.png", NULL);
  tileSprites[tile_pipe_12][0] = load_png("images/blocks/pipe_12.png", NULL);
  tileSprites[tile_pipe_13][0] = load_png("images/blocks/pipe_13.png", NULL);
  tileSprites[tile_pipe_14][0] = load_png("images/blocks/pipe_14.png", NULL);
  tileSprites[tile_pipe_15][0] = load_png("images/blocks/pipe_15.png", NULL);

  tileSprites[tile_generator_off][0] =
      load_png("images/blocks/generator.png", NULL);
  tileSprites[tile_generator_on][0] =
      load_png("images/blocks/generator_4.png", NULL);
  tileSprites[tile_generator_1][0] =
      load_png("images/blocks/generator_2.png", NULL);
  tileSprites[tile_generator_2][0] =
      load_png("images/blocks/generator_3.png", NULL);

  tileSprites[tile_energydrink][0] =
      load_png("images/blocks/energydrink.png", NULL);
  tileSprites[tile_ammo_pistol][0] =
      load_png("images/blocks/ammo_pistol.png", NULL);

  tileSprites[tile_light_cage_1][0] =
      load_png("images/blocks/light_cage_1.png", NULL);
  tileSprites[tile_light_cage_2][0] =
      load_png("images/blocks/light_cage_2.png", NULL);
  tileSprites[tile_light_cage_3][0] =
      load_png("images/blocks/light_cage_3.png", NULL);
  tileSprites[tile_light_cage_4][0] =
      load_png("images/blocks/light_cage_4.png", NULL);

  tileSprites[tile_crate1_1][0] = load_png("images/blocks/crate1_1.png", NULL);
  tileSprites[tile_crate1_2][0] = load_png("images/blocks/crate1_2.png", NULL);
  tileSprites[tile_crate1_3][0] = load_png("images/blocks/crate1_3.png", NULL);
  tileSprites[tile_crate1_4][0] = load_png("images/blocks/crate1_4.png", NULL);
  tileSprites[tile_crate1_5][0] = load_png("images/blocks/crate1_5.png", NULL);

  tileSprites[tile_cement_radioactive_1][0] =
      load_png("images/blocks/cement_radioactive_1.png", NULL);
  tileSprites[tile_cement_radioactive_2][0] =
      load_png("images/blocks/cement_radioactive_2.png", NULL);
  tileSprites[tile_cement_radioactive_3][0] =
      load_png("images/blocks/cement_radioactive_3.png", NULL);
  tileSprites[tile_cement_radioactive_4][0] =
      load_png("images/blocks/cement_radioactive_4.png", NULL);

  tileSprites[tile_elevator_control][0] =
      load_png("images/blocks/elevator_control.png", NULL);

  // Load ALL 33 elevator images
  tileSprites[tile_elevator_1][0] =
      load_png("images/blocks/elevator_1.png", NULL);
  tileSprites[tile_elevator_2][0] =
      load_png("images/blocks/elevator_2.png", NULL);
  tileSprites[tile_elevator_3][0] =
      load_png("images/blocks/elevator_3.png", NULL);
  tileSprites[tile_elevator_4][0] =
      load_png("images/blocks/elevator_4.png", NULL);
  tileSprites[tile_elevator_5][0] =
      load_png("images/blocks/elevator_5.png", NULL);
  tileSprites[tile_elevator_6][0] =
      load_png("images/blocks/elevator_6.png", NULL);
  tileSprites[tile_elevator_7][0] =
      load_png("images/blocks/elevator_7.png", NULL);
  tileSprites[tile_elevator_8][0] =
      load_png("images/blocks/elevator_8.png", NULL);
  tileSprites[tile_elevator_9][0] =
      load_png("images/blocks/elevator_9.png", NULL);
  tileSprites[tile_elevator_10][0] =
      load_png("images/blocks/elevator_10.png", NULL);
  tileSprites[tile_elevator_11][0] =
      load_png("images/blocks/elevator_11.png", NULL);
  tileSprites[tile_elevator_12][0] =
      load_png("images/blocks/elevator_12.png", NULL);
  tileSprites[tile_elevator_13][0] =
      load_png("images/blocks/elevator_13.png", NULL);
  tileSprites[tile_elevator_14][0] =
      load_png("images/blocks/elevator_14.png", NULL);
  tileSprites[tile_elevator_15][0] =
      load_png("images/blocks/elevator_15.png", NULL);
  tileSprites[tile_elevator_16][0] =
      load_png("images/blocks/elevator_16.png", NULL);
  tileSprites[tile_elevator_17][0] =
      load_png("images/blocks/elevator_17.png", NULL);
  tileSprites[tile_elevator_18][0] =
      load_png("images/blocks/elevator_18.png", NULL);
  tileSprites[tile_elevator_19][0] =
      load_png("images/blocks/elevator_19.png", NULL);
  tileSprites[tile_elevator_20][0] =
      load_png("images/blocks/elevator_20.png", NULL);
  tileSprites[tile_elevator_21][0] =
      load_png("images/blocks/elevator_21.png", NULL);
  tileSprites[tile_elevator_22][0] =
      load_png("images/blocks/elevator_22.png", NULL);
  tileSprites[tile_elevator_23][0] =
      load_png("images/blocks/elevator_23.png", NULL);
  tileSprites[tile_elevator_24][0] =
      load_png("images/blocks/elevator_24.png", NULL);
  tileSprites[tile_elevator_25][0] =
      load_png("images/blocks/elevator_25.png", NULL);
  tileSprites[tile_elevator_26][0] =
      load_png("images/blocks/elevator_26.png", NULL);
  tileSprites[tile_elevator_27][0] =
      load_png("images/blocks/elevator_27.png", NULL);
  tileSprites[tile_elevator_28][0] =
      load_png("images/blocks/elevator_28.png", NULL);
  tileSprites[tile_elevator_29][0] =
      load_png("images/blocks/elevator_29.png", NULL);
  tileSprites[tile_elevator_30][0] =
      load_png("images/blocks/elevator_30.png", NULL);
  tileSprites[tile_elevator_31][0] =
      load_png("images/blocks/elevator_31.png", NULL);
  tileSprites[tile_elevator_32][0] =
      load_png("images/blocks/elevator_32.png", NULL);
  tileSprites[tile_elevator_33][0] =
      load_png("images/blocks/elevator_33.png", NULL);

  tileSprites[tile_elevator_shroud_1][0] =
      load_png("images/blocks/elevator_shroud_1.png", NULL);
  tileSprites[tile_elevator_shroud_2][0] =
      load_png("images/blocks/elevator_shroud_2.png", NULL);
  tileSprites[tile_elevator_shroud_3][0] =
      load_png("images/blocks/elevator_shroud_3.png", NULL);
  tileSprites[tile_elevator_shroud_4][0] =
      load_png("images/blocks/elevator_shroud_4.png", NULL);
  tileSprites[tile_elevator_shroud_5][0] =
      load_png("images/blocks/elevator_shroud_5.png", NULL);
  tileSprites[tile_elevator_shroud_6][0] =
      load_png("images/blocks/elevator_shroud_6.png", NULL);

  tileSprites[tile_pistol_magazine][0] =
      load_png("images/blocks/pistol_magazine.png", NULL);
  tileSprites[tile_pistol_box][0] =
      load_png("images/blocks/pistol_box.png", NULL);

  tileSprites[tile_grass_3][0] = load_png("images/blocks/grass_3.png", NULL);

  tileSprites[tile_cover_1][0] = load_png("images/blocks/cover_1.png", NULL);

  tileSprites[tile_roof_1][0] = load_png("images/blocks/roof_1.png", NULL);
  tileSprites[tile_roof_2][0] = load_png("images/blocks/roof_2.png", NULL);
  tileSprites[tile_roof_3][0] = load_png("images/blocks/roof_3.png", NULL);
  tileSprites[tile_roof_4][0] = load_png("images/blocks/roof_4.png", NULL);
  tileSprites[tile_roof_5][0] = load_png("images/blocks/roof_5.png", NULL);
  tileSprites[tile_roof_6][0] = load_png("images/blocks/roof_6.png", NULL);

  tileSprites[tile_brick_1][0] = load_png("images/blocks/brick_1.png", NULL);
  tileSprites[tile_brick_door_1][0] =
      load_png("images/blocks/brick_door_1.png", NULL);
  tileSprites[tile_brick_door_2][0] =
      load_png("images/blocks/brick_door_2.png", NULL);
  tileSprites[tile_brown_door_1][0] =
      load_png("images/blocks/brown_door_1.png", NULL);
  tileSprites[tile_brown_door_2][0] =
      load_png("images/blocks/brown_door_2.png", NULL);
  tileSprites[tile_door_1][0] = load_png("images/blocks/door_1.png", NULL);
  tileSprites[tile_door_2][0] = load_png("images/blocks/door_2.png", NULL);
  tileSprites[tile_brick_2][0] = load_png("images/blocks/brick_1.png", NULL);
  tileSprites[tile_brick_window_1][0] =
      load_png("images/blocks/brick_window_1.png", NULL);
  tileSprites[tile_fence][0] = load_png("images/blocks/fence.png", NULL);
  tileSprites[tile_wallpaper_1][0] =
      load_png("images/blocks/wallpaper_1.png", NULL);

  tileSprites[tile_temperature_1][0] =
      load_png("images/blocks/temperature_1.png", NULL);
  tileSprites[tile_temperature_1][1] =
      load_png("images/blocks/temperature_2.png", NULL);
  tileSprites[tile_temperature_1][3] =
      load_png("images/blocks/temperature_1.png", NULL);
  tileSprites[tile_temperature_1][4] =
      load_png("images/blocks/temperature_2.png", NULL);

  tileSprites[tile_roof_chimney][0] =
      load_png("images/blocks/roof_chimney.png", NULL);

  tileSprites[tile_roof_chimney_1][0] =
      load_png("images/blocks/roof_chimney_1.png", NULL);
  tileSprites[tile_roof_chimney_1][1] =
      load_png("images/blocks/roof_chimney_2.png", NULL);
  tileSprites[tile_roof_chimney_1][2] =
      load_png("images/blocks/roof_chimney_3.png", NULL);
  tileSprites[tile_roof_chimney_1][3] =
      load_png("images/blocks/roof_chimney_4.png", NULL);

  tileSprites[tile_cement_wood][0] =
      load_png("images/blocks/cement_wood.png", NULL);

  tileSprites[tile_water][0] = load_png("images/blocks/water.png", NULL);
  tileSprites[tile_water_cement_left_1][0] =
      load_png("images/blocks/water_cement_left_1.png", NULL);
  tileSprites[tile_water_cement_left_2][0] =
      load_png("images/blocks/water_cement_left_2.png", NULL);
  tileSprites[tile_water_cement_left_3][0] =
      load_png("images/blocks/water_cement_left_3.png", NULL);
  tileSprites[tile_water_cement_right_1][0] =
      load_png("images/blocks/water_cement_right_1.png", NULL);
  tileSprites[tile_water_cement_right_2][0] =
      load_png("images/blocks/water_cement_right_2.png", NULL);
  tileSprites[tile_water_cement_right_3][0] =
      load_png("images/blocks/water_cement_right_3.png", NULL);
  tileSprites[tile_water_cement_middle][0] =
      load_png("images/blocks/water_cement_middle.png", NULL);
  // Weapon pickups
  tileSprites[tile_dirt][0] = load_png("images/blocks/dirt.png", NULL);
  tileSprites[tile_grass_dirt][0] =
      load_png("images/blocks/grass_dirt.png", NULL);
  tileSprites[tile_pistol][0] = load_png("images/blocks/pistol.png", NULL);
  tileSprites[tile_mp5][0] = load_png("images/blocks/mp5.png", NULL);
  tileSprites[tile_ppsh][0] = load_png("images/blocks/ppsh.png", NULL);
  tileSprites[tile_minigun][0] = load_png("images/blocks/minigun.png", NULL);
  tileSprites[tile_remington][0] =
      load_png("images/blocks/remington.png", NULL);

  tileSprites[tile_ammo_mp5][0] = load_png("images/blocks/ammo_mp5.png", NULL);
  tileSprites[tile_ammo_remington][0] =
      load_png("images/blocks/ammo_remington.png", NULL);
  tileSprites[tile_ammo_ppsh][0] =
      load_png("images/blocks/ammo_ppsh.png", NULL);
  tileSprites[tile_ammo_minigun][0] =
      load_png("images/blocks/ammo_minigun.png", NULL);

  // NPC's
  tileSprites[tile_npc_allan][0] = load_png("images/npc/allan.png", NULL);
  tileSprites[tile_npc_gerald][0] = load_png("images/npc/gerald.png", NULL);

  // Readable
  tileSprites[tile_readable_paper][0] =
      load_png("images/blocks/paper.png", NULL);
  tileSprites[tile_readable_statue][0] =
      load_png("images/blocks/statue.png", NULL);

  // Spawners
  tileSprites[tile_spawn_player][0] = load_png("images/blocks/spawn.png", NULL);
  tileSprites[tile_spawn_mutant][0] =
      load_png("images/enemys/mutant/left_1.png", NULL);
  // Level end block
  tileSprites[tile_teleporter][0] =
      load_png("images/blocks/teleporter.png", NULL);
}

// Change frame
void tileMap::change_frame() {
  if (frame < 3) {
    frame++;
  } else {
    frame = 0;
  }
}
END_OF_FUNCTION(change_frame)

void tileMap::load(string fileName) {
  // Save name
  mapName = fileName;

  // Change size
  string fileLoad = fileName + ".txt";
  ifstream findSize(fileLoad.c_str());
  width = 0;
  height = 0;
  int data;
  while (findSize >> data) {
    if (height == 0) {
      width++;
    }
    if (findSize.peek() == '\n') {
      height++;
    }
  }

  // Setup Map
  if (fileName != "blank") {
    mapTiles.clear();
    mapTilesBack.clear();

    fileLoad = fileName + ".txt";
    ifstream read(fileLoad.c_str());

    for (int t = 0; t < height; t++) {
      for (int i = 0; i < width; i++) {
        int newTileType;
        read >> newTileType;
        // Set tile type
        tile newTile(newTileType);
        newTile.setX(i * 64);
        newTile.setY(t * 64);
        mapTiles.push_back(newTile);
      }
    }
    read.close();

    fileLoad = fileName + "_back.txt";
    ifstream read2(fileLoad.c_str());

    for (int t = 0; t < height; t++) {
      for (int i = 0; i < width; i++) {
        int newTileType;
        read2 >> newTileType;
        // Set tile type
        tile newTile(newTileType);
        newTile.setX(i * 64);
        newTile.setY(t * 64);
        mapTilesBack.push_back(newTile);
      }
    }
    read2.close();
  }
}

// Reload last map
void tileMap::reload(bool instant) {
  load(mapName);

  if (!instant) {
    x = 0;
    y = 0;
  }
}

// Draw tile map
void tileMap::draw_map(BITMAP* tempSprite) {
  for (unsigned int i = 0; i < mapTilesBack.size(); i++) {
    if ((mapTilesBack.at(i).getX() >= x - 256) &&
        (mapTilesBack.at(i).getX() < x + 1280) &&
        (mapTilesBack.at(i).getY() >= y - 256) &&
        (mapTilesBack.at(i).getY() < y + 960)) {
      if (mapTilesBack.at(i).getType() != spawn) {
        mapTilesBack.at(i).draw_tile(tempSprite, x, y, frame);
      }
    }
  }
  for (unsigned int i = 0; i < mapTiles.size(); i++) {
    if ((mapTiles.at(i).getX() >= x - 256) &&
        (mapTiles.at(i).getX() < x + 1280) &&
        (mapTiles.at(i).getY() >= y - 256) &&
        (mapTiles.at(i).getY() < y + 960)) {
      if (mapTilesBack.at(i).getType() != spawn) {
        mapTiles.at(i).draw_tile(tempSprite, x, y, frame);
      }
    }
  }
}

tileMap::~tileMap() {
  mapTiles.clear();
  mapTilesBack.clear();
}
