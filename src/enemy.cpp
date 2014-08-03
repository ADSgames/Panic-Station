#include "enemy.h"

enemy::enemy( int newX, int newY, int newType){
  //Set enemy variables
  canFall = true;
  dead = false;
  jumping = false;
  characterDir = 0;
  walking_counter = 0;

  walking_animation_sequence = 0;
  jumpChance = 0;
  maxSteps = 0;
  minSteps = 0;
  jumpHeight = 0;
  walkChance = 0;
  jumpSpeed = 0;
  speed = 0;
  health = 0;
  fireRate = 0;
  bulletCounter = 0;
  bulletSpeed = 0;
  bulletDirection = 0;
  bulletHeight = 0;

  x = newX;
  y = newY;
  type = newType;
}

// 0-3 left, 4-7 right, 8-11 up
void enemy::load_images(){
  //If enemy is a mutant
  if(type == enemy_mutant){
    enemy_images[0] = load_bitmap ( "images/enemys/mutant/left_1.png", NULL);
    enemy_images[1] = load_bitmap ( "images/enemys/mutant/left_2.png", NULL);
    enemy_images[2] = load_bitmap ( "images/enemys/mutant/left_3.png", NULL);
    enemy_images[3] = load_bitmap ( "images/enemys/mutant/left_4.png", NULL);

    enemy_images[4] = load_bitmap ( "images/enemys/mutant/right_1.png", NULL);
    enemy_images[5] = load_bitmap ( "images/enemys/mutant/right_2.png", NULL);
    enemy_images[6] = load_bitmap ( "images/enemys/mutant/right_3.png", NULL);
    enemy_images[7] = load_bitmap ( "images/enemys/mutant/right_4.png", NULL);

    enemy_images[8] = load_bitmap ( "images/enemys/mutant/left_1.png", NULL);
    enemy_images[9] = load_bitmap ( "images/enemys/mutant/right_1.png", NULL);

    enemy_images[10] = load_bitmap ( "images/enemys/mutant/dead.png", NULL);

    jumpChance = 100;
    maxSteps = 100;
    minSteps = 20;
    jumpHeight = 128;
    walkChance = 20;
    jumpSpeed = 2;
    speed = 3;
    health = 100;
    fireRate = 0;

  }

    if(type == enemy_sentry){
        enemy_images[0] = load_bitmap ( "images/enemys/sentry/left.png", NULL);
        enemy_images[1] = load_bitmap ( "images/enemys/sentry/left.png", NULL);
        enemy_images[2] = load_bitmap ( "images/enemys/sentry/left.png", NULL);
        enemy_images[3] = load_bitmap ( "images/enemys/sentry/left.png", NULL);

        enemy_images[4] = load_bitmap ( "images/enemys/sentry/right.png", NULL);
        enemy_images[5] = load_bitmap ( "images/enemys/sentry/right.png", NULL);
        enemy_images[6] = load_bitmap ( "images/enemys/sentry/right.png", NULL);
        enemy_images[7] = load_bitmap ( "images/enemys/sentry/right.png", NULL);

        enemy_images[8] = load_bitmap ( "images/enemys/sentry/left.png", NULL);
        enemy_images[9] = load_bitmap ( "images/enemys/sentry/right.png", NULL);


        enemy_images[10] = load_bitmap ( "images/enemys/sentry/dead.png", NULL);

        jumpChance = 0;
        maxSteps = 0;
        minSteps = 0;
        jumpHeight = 0;
        walkChance = 0;
        jumpSpeed = 0;
        speed = 0;
        fireRate = 30;
        bulletSpeed = 30;
        bulletDirection = -1;
        bulletHeight = 20;

        health = 500;

  }
  width = enemy_images[0] -> w;
  height = enemy_images[0] -> h;
}

// Load sounds
void enemy::load_sounds(){
  if(type == enemy_mutant){
    walk1 = load_sample("sounds/walk_stone.wav");
    walk2 = load_sample("sounds/walk_stone.wav");
    jump = load_sample("sounds/jump_1.wav");
    die = load_sample("sounds/alarm.wav");
    getItem = load_sample("sounds/get_item.wav");
    getBonus = load_sample("sounds/get_bonus.wav");
  }
  else if(type == enemy_sentry){
    walk1 = load_sample("sounds/walk_stone.wav");
    walk2 = load_sample("sounds/walk_stone.wav");
    jump = load_sample("sounds/jump_1.wav");
    die = load_sample("sounds/alarm.wav");
    getItem = load_sample("sounds/get_item.wav");
    getBonus = load_sample("sounds/get_bonus.wav");
  }

}

// Return X
int enemy::getX(){
  return x;
}

// Return Y
int enemy::getY(){
  return y;
}


// Dead?
bool enemy::getDead(){
  return dead;
}

//Set dead
void enemy::setDead(bool newDead){
  dead = newDead;
}

//Draw enemy
void enemy::draw(BITMAP* temp, int tile_map_x, int tile_map_y){
  //Only draw if on screen (save CPU power)!
  bool onScreen = false;
  if(x + width - tile_map_x > 0 && x - tile_map_x < 1280 && y + height - tile_map_y > 0 && y - tile_map_y < 960){
    onScreen = true;
  }
  if(onScreen){
    if(!dead){
      if(type==enemy_mutant){
            rectfill(temp,(x - tile_map_x),(y - tile_map_y),(x - tile_map_x)+52,(y - tile_map_y)-8,makecol(255,255,255));
            rectfill(temp,(x - tile_map_x)+2,(y - tile_map_y)-2,(x - tile_map_x)+health/2,(y - tile_map_y)-6,makecol(55+health*2,0,0));
      }
      if(type==enemy_sentry){
            rectfill(temp,(x - tile_map_x),(y - tile_map_y)-10,(x - tile_map_x)+52,(y - tile_map_y)-18,makecol(255,255,255));
            rectfill(temp,(x - tile_map_x)+2,(y - tile_map_y)-12,(x - tile_map_x)+health/10,(y - tile_map_y)-16,makecol(55+health/5*2,0,0));
      }

      if(jumping || canFall){
        if(characterDir == LEFT){
          draw_sprite( temp, enemy_images[8], x - tile_map_x, y - tile_map_y);
        }
        else{
         draw_sprite( temp, enemy_images[9], x - tile_map_x, y - tile_map_y);
        }
      }
      else{
        draw_sprite( temp, enemy_images[characterDir + walking_animation_sequence/ANIMATION_SPEED], x - tile_map_x, y - tile_map_y);
      }

      //Draw bullets
      for(int i = 0; i < bullets.size(); i++){
        bullets.at(i).draw(temp,tile_map_x, tile_map_y);
      }
    }
    else{
      draw_sprite( temp, enemy_images[10], x - tile_map_x, y - tile_map_y);
    }
  }
}

//Movement
void enemy::update(tileMap *newMap, player *newPlayer){


  //Only update if on screen (save CPU power)!
  bool onScreen = false;
  if(x + width - newMap -> x > 0 && x - newMap -> x < 1280 && y + height - newMap -> y > 0 && y - newMap -> y < 960){
    onScreen = true;
  }
  if(onScreen){
    if(!dead ){
        if(fireRate!=0){
        bulletCounter++;
        if(bulletCounter>=fireRate){
            projectile newBullet( 0, x + 30, y + bulletHeight, bulletSpeed * bulletDirection);
            bullets.push_back(newBullet);
            bulletCounter=0;
            }
    }
      //Collision stuff
      bool canMoveLeft = true;
      bool canMoveRight = true;
      bool canClimbUp = true;
      bool canClimbDown = true;
      bool canClimbUp2 = false;
      bool canClimbDown2 = false;
      bool canJump = true;
      bool canJumpUp = true;
      bool inLiquid = false;

      //Check for collision
      for(int i = 0; i < newMap -> mapTiles.size(); i++){
        //Only compare to near by tiles to save CPU power!
        if( collisionAny( x - 64, x + 128, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 64, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          if(newMap -> mapTiles.at(i).getAttribute() == solid || newMap -> mapTiles.at(i).getAttribute() == cover){
            if(collisionAny(x - speed, x + width - speed, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
               collisionLeft(x - speed, x + width - speed, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
              canMoveLeft = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == solid || newMap -> mapTiles.at(i).getAttribute() == cover){
            if(collisionAny(x + speed, x + width + speed, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
               collisionRight(x + speed, x + width + speed, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
              canMoveRight = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == climb){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              canClimbUp2 = true;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == climb){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height + 16, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              canClimbDown2 = true;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == solid){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 16, y, newMap -> mapTiles.at(i).getY(),newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              canClimbUp = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == solid){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height + 16, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              canClimbDown = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() != gas && newMap -> mapTiles.at(i).getAttribute() != liquid){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              canJump = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() != gas && newMap -> mapTiles.at(i).getAttribute() != liquid){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight(), y, y + 144) &&
            collisionTop(newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64, y + yVelocity, y + height + 16 + yVelocity)){
              canJumpUp = false;
            }
          }
          if(newMap -> mapTiles.at(i).getAttribute() == liquid){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 16, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              inLiquid = true;
            }
          }
        }
      }

      //Check for points and dangers
      for(int i = 0; i < newMap -> mapTiles.size(); i++){
        if(collisionAny(x - width*2, x + width*2, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - height*2, y + height*2, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){

          //Die
          if(newMap -> mapTiles.at(i).getAttribute() == harmful){
            if(collisionAny(x, x + width, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 16, y + height, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
              dead = true;
            }
          }
        }
      }

      // Check collision with bullets
      for(int i = 0; i < newPlayer -> getBullets() -> size(); i++){
        if(collisionAny(x, x + width, newPlayer -> getBullets() -> at(i).getX(), newPlayer -> getBullets() -> at(i).getX() + 64, y, y + height, newPlayer -> getBullets() -> at(i).getY(), newPlayer -> getBullets() -> at(i).getY() + 64)){
          newPlayer -> getBullets() -> at(i).setContact(true);
          health-= newPlayer -> weapon[newPlayer -> currentWeapon].damage;

        }
      }

      // AI set direction of walking
      if( walking_counter == 0){
        if(random(0,walkChance) == 0 && walkChance != 0){
          if(random(0,1) == 0){
            characterDir = RIGHT;
          }
          else{
            characterDir = LEFT;
          }
          walking_counter = random(minSteps,maxSteps);
        }
      }
      if( walking_counter > 0){
        walking_counter--;
      }

      //Move right
      if(characterDir == RIGHT && walking_counter > 0){
        if(canMoveRight){
          x += speed;
          walking_animation_sequence++;
          if(walking_animation_sequence %(ANIMATION_SPEED * 2) == 0 && !canFall && !jumping){
            if(random(0,10)){
              play_sample(walk1,255,125,1000,0);
            }
            else{
              play_sample(walk2,255,125,1000,0);
            }
          }
        }
      }

      //Move left
      if(characterDir == LEFT && walking_counter > 0){
        if(canMoveLeft){
          x -= speed;
          walking_animation_sequence++;
          if(walking_animation_sequence %(ANIMATION_SPEED * 2) == 0 && !canFall && !jumping){
            if(random(0,10)){
              play_sample(walk1,255,125,1000,0);
            }
            else{
              play_sample(walk2,255,125,1000,0);
            }
          }
        }
      }

      //Jumping
      if(jumping && canJumpUp){
        if(canFall || jump_height > 0 ){
          y -= yVelocity;
        }

        if(jump_height <= 0){
          if(yVelocity > -16){
            yVelocity -= jumpSpeed;
          }
          else{
            yVelocity = 0;
            jumping = false;
          }
        }
        else{
          jump_height -= yVelocity;
        }
      }
      else if(jumping && !canJumpUp){
        jumping = false;
      }

      //Jump
      if(random(0,jumpChance) == 0 && jumpChance != 0){
        if(inLiquid){
          y -= 16;
        }
        else if(!canFall && canJump && !jumping){
          yVelocity = 16;
          jump_height = jumpHeight;
          jumping = true;
        }
      }

      // Reset animation sequence
      if(walking_animation_sequence >= ANIMATION_SPEED * 4 ){
        walking_animation_sequence = 0;
      }

      // Update bullets
      for(int i = 0; i < bullets.size(); i++){
        bullets.at(i).update();
        if(bullets.at(i).getContact(newMap) && bullets.at(i).getContactFrameCounter() == 10){
          bullets.erase(bullets.begin() + i);
        }
      }

    //Still falls when dead
    }






    canFall = true;
    bool smoothFall = false;
    //Falling (calculated separately to ensure collision accurate)
    for(int i = 0; i < newMap -> mapTiles.size(); i++){
      if(collisionAny(x - width*2, x + width*2, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - height*2, y + height*2, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
        if(newMap -> mapTiles.at(i).getAttribute() == solid || newMap -> mapTiles.at(i).getAttribute() == harmful && dead){
          if(collisionAny(x, x + 96, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
             collisionTop(y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64)){
            canFall = false;
            if(!collisionAny(x, x + 96, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 129, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
             !collisionTop(y, y + 129, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64)){
              smoothFall = true;
            }
          }
        }
      }
    }
    if(dead){
        jumping=false;
    }
    //Health
    if(health<1){
      dead = true;
    }

    //Fall
    if(canFall && !jumping){
      y += 16;
    }
    //Smooth falling
    if(smoothFall){
      y += 1;
    }
  }
}

// Deconstruct enemies
enemy::~enemy(){
  bullets.clear();

  for(int i = 0; i < 11; i++){
		if(enemy_images[i]){
			destroy_bitmap(enemy_images[i]);
		}
	}
  destroy_sample( walk1);
  destroy_sample( walk2);
  destroy_sample( jump);
  destroy_sample( die);
  destroy_sample( getItem);
  destroy_sample( getBonus);
}
