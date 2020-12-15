#ifndef PERSON_H
#define PERSON_H

#include <allegro.h>
#include <loadpng.h>
#include <vector>

#include "globals.h"
#include "player.h"
#include "projectile.h"
#include "tools.h"

#include "tileMap.h"

#define ANIMATION_SPEED 5
#define JUMPING_HEIGHT 192

class person {
 public:
  person();

  void load_images();
  void load_sounds();

  int getX();
  int getY();

  bool getDead();
  void setDead(bool newDead);

  void update(tileMap* newMap, player* newPlayer);
  void draw(BITMAP* temp, int tile_map_x, int tile_map_y);

  ~person();

 protected:
  int x;
  int y;

  int width;
  int height;

  int speed;
  int type;

  // Customize!
  int jumpChance;
  int maxSteps;
  int minSteps;
  int jumpHeight;
  int walkChance;
  int jumpSpeed;

  int health;
  int fireRate;
  int bulletCounter;
  int bulletSpeed;
  int bulletDirection;
  int bulletHeight;

  bool canFall;
  bool jumping;
  bool dead;
  int walking_animation_sequence;
  int jumping_animation_sequence;
  int jump_height;
  int characterDir;
  int yVelocity;
  int walking_counter;

  vector<projectile> bullets;

  // 0-3 left, 4-7 right, 8 jump left 9 jump right 10 dead
  BITMAP* images[36];
};

#endif  // PERSON_H
