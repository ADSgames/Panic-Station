#include "Game.h"

Game::Game()
{
  // Creates a random number generator (based on time)
  srand (time(NULL));

  // Other Sprites
  buffer = create_bitmap( 1280, 960);

  // Player
  character.load_images();
  character.load_sounds();

  // Create map
  tile_map = new tileMap("data/levels/level_01");

  // Init
  init();
}

void Game::init(){
  // Clears enemies
  badGuy.clear();

  // Create map
  tile_map -> reload( true);

  // Variables
  character.setDead(false);

  // Load enemies
  for(int i = 0; i < tile_map -> mapTiles.size(); i++){
    if(tile_map -> mapTiles.at(i).getType() == tile_spawn_mutant){
      enemy *newBadGuy = new enemy( tile_map -> mapTiles.at(i).getX(), tile_map -> mapTiles.at(i).getY(), enemy_mutant);
      newBadGuy -> load_images();
      newBadGuy -> load_sounds();
      badGuy.push_back(newBadGuy);

      tile_map -> mapTiles.at(i).setType(0);
    }
  }

  //Create duplicate map with only solids for updating enemies
  newTileMap = new tileMap("blank");

  for(int i = 0; i < tile_map -> mapTiles.size(); i++){
    if(tile_map -> mapTiles.at(i).getAttribute() != gas){
      newTileMap -> mapTiles.push_back(tile_map -> mapTiles.at(i));
    }
  }

  // Spawn character
  character.spawncommand(tile_map);

  /*draw( false);
  highcolor_fade_in( buffer,16);*/

  set_alpha_blender();
}

void Game::update()
{
  poll_joystick();

  // Character movements (runs only every 2nd loop)
  if(frames_done % 2 == 0){
    character.update(tile_map);

    for(int i = 0; i < badGuy.size(); i++){
      badGuy.at(i) -> update(newTileMap, &character);
    }
  }

  // Tile map positions
  newTileMap -> x = tile_map -> x;
  newTileMap -> y = tile_map -> y;

  if(key[KEY_R]){
    enemy* newBadGuy = new enemy( character.getX(), character.getY(), enemy_mutant);
    newBadGuy -> load_images();
    newBadGuy -> load_sounds();
    badGuy.push_back(newBadGuy);
    rest(10);
  }
  if(key[KEY_T]){
    enemy* newBadGuy = new enemy( character.getX(), character.getY(), enemy_sentry);
    newBadGuy -> load_images();
    newBadGuy -> load_sounds();
    badGuy.push_back(newBadGuy);
    rest(100);
  }

  // Back to menu
  if( key[KEY_M] || joy[0].button[6].b){
    set_next_state( STATE_MENU);
  }

  // Die
  if(character.getDead() || character.getFinishLevel()){
    init();
    character.setFinishLevel( false);
  }

  // Respawn
  if(key[KEY_Y]){
    character.spawncommand(tile_map);
  }
}

void Game::draw( bool toScreen)
{
  // Black background (just in case)
  rectfill( buffer, 0, 0, 1280, 960, makecol(0,0,0));

  // Draw tiles
  tile_map -> draw_map(buffer);

  // Draw enemies
  for(int i = 0; i < badGuy.size(); i++){
    badGuy.at(i) -> draw(buffer, tile_map -> x, tile_map -> y);
  }

  // Draw character
  character.draw(buffer, tile_map -> x, tile_map -> y);

  // Draw buffer
  if( toScreen){
    stretch_sprite( screen, buffer, 0, 0, SCREEN_W, SCREEN_H);
  }
}

Game::~Game()
{
  destroy_bitmap( buffer);

  badGuy.clear();

  // Fade out
  highcolor_fade_out(16);
}
