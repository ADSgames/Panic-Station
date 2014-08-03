#include "player.h"

player::player(){

  //Set variables
  x = 128;
  y = 128;


  //Define weapon attributes
  weapon[0].ammunition = 100;
  weapon[1].ammunition = 0;
  weapon[2].ammunition = 0;
  weapon[3].ammunition = 0;
  weapon[4].ammunition = 0;
  weapon[5].ammunition = 0;

  weapon[1].speed=60;
  weapon[2].speed=60;
  weapon[3].speed=60;
  weapon[4].speed=60;
  weapon[5].speed=60;

  weapon[1].magazineSize=8;
  weapon[2].magazineSize=30;
  weapon[3].magazineSize=71;
  weapon[4].magazineSize=500;
  weapon[5].magazineSize=5;

  weapon[1].magazine=0;
  weapon[2].magazine=0;
  weapon[3].magazine=0;
  weapon[4].magazine=0;
  weapon[5].magazine=0;

  weapon[1].reloadSpeed=50;
  weapon[2].reloadSpeed=100;
  weapon[3].reloadSpeed=200;
  weapon[4].reloadSpeed=1000;
  weapon[5].reloadSpeed=200;

  weapon[1].rateOfFire=-1;
  weapon[2].rateOfFire=3;
  weapon[3].rateOfFire=2;
  weapon[4].rateOfFire=0;
  weapon[5].rateOfFire=25;

  weapon[1].aquired=false;
  weapon[2].aquired=false;
  weapon[3].aquired=false;
  weapon[4].aquired=false;
  weapon[5].aquired=false;

  weapon[1].bulletsFired=1;
  weapon[2].bulletsFired=1;
  weapon[3].bulletsFired=1;
  weapon[4].bulletsFired=1;
  weapon[5].bulletsFired=3;

  weapon[1].damage=10;
  weapon[2].damage=15;
  weapon[3].damage=15;
  weapon[4].damage=50;
  weapon[5].damage=20;

  triggerReleased=true;
  canShoot=true;

  reloadTicks = 0;

  stamina=100;
  staminaLoop=0;
  staminaBoost=false;

  level=1;

  health=100;
  oxygen=100;
  oxygenHarm=0;

  currentWeapon = 0;
  weaponScrollLoop = 0;

  fallheight = 0;


  material=0;

  initial_spawn = false;

  isTalkingToNpc = false;
  npc_ID = 0;

  isReadingBlock = false;
  read_ID = 0;

  deathcount = 0;

  height = 0;
  canFall = true;
  jumping = false;
  jumping_animation_done = true;
  dead = false;
  shooting = false;
  blindfiring = false;
  isSprinting=false;
  isCrouching=false;

  moving_to_cover = false;

  switch_loop = 0;
  switch_frame = 0;
  switch_direction = false;

  elevator_called = false;
  elevator_loop = 0;
  elevator_frame = 0;
  elevator_direction = false;

  shooting_animation_sequence = 0;
  walking_animation_sequence = 0;
  jumping_animation_sequence = 0;

  jump_height = 0;
  characterDir = 0; //use LEFT and RIGHT
  yVelocity = 0;
}

//Load images of player
// 0-3 left, 4-7 right, 8-11 up
void player::load_images(){
  player_images[0] = load_bitmap ( "images/character/left_1.png", NULL);
  player_images[1] = load_bitmap ( "images/character/left_2.png", NULL);
  player_images[2] = load_bitmap ( "images/character/left_3.png", NULL);
  player_images[3] = load_bitmap ( "images/character/left_4.png", NULL);

  player_images[4] = load_bitmap ( "images/character/right_1.png", NULL);
  player_images[5] = load_bitmap ( "images/character/right_2.png", NULL);
  player_images[6] = load_bitmap ( "images/character/right_3.png", NULL);
  player_images[7] = load_bitmap ( "images/character/right_4.png", NULL);

  player_images[8] = load_bitmap ( "images/character/up_1.png", NULL);
  player_images[9] = load_bitmap ( "images/character/up_2.png", NULL);
  player_images[10] = load_bitmap ( "images/character/up_3.png", NULL);
  player_images[11] = load_bitmap ( "images/character/up_4.png", NULL);

  player_images[12] = load_bitmap ( "images/character/jump_left_1.png", NULL);
  player_images[13] = load_bitmap ( "images/character/jump_left_2.png", NULL);
  player_images[14] = load_bitmap ( "images/character/jump_left_3.png", NULL);
  player_images[15] = load_bitmap ( "images/character/jump_left_4.png", NULL);
  player_images[16] = load_bitmap ( "images/character/jump_left_5.png", NULL);
  player_images[17] = load_bitmap ( "images/character/jump_left_6.png", NULL);

  player_images[18] = load_bitmap ( "images/character/jump_right_1.png", NULL);
  player_images[19] = load_bitmap ( "images/character/jump_right_2.png", NULL);
  player_images[20] = load_bitmap ( "images/character/jump_right_3.png", NULL);
  player_images[21] = load_bitmap ( "images/character/jump_right_4.png", NULL);
  player_images[22] = load_bitmap ( "images/character/jump_right_5.png", NULL);
  player_images[23] = load_bitmap ( "images/character/jump_right_6.png", NULL);

  player_images[24] = load_bitmap ( "images/character/shoot_left.png", NULL);
  player_images[25] = load_bitmap ( "images/character/shoot_right.png", NULL);

  player_images[30] = load_bitmap ( "images/character/crouch_right_1.png", NULL);
  player_images[31] = load_bitmap ( "images/character/crouch_left_1.png", NULL);
  player_images[32] = load_bitmap ( "images/character/crouch_shoot_right_1.png", NULL);
  player_images[33] = load_bitmap ( "images/character/crouch_shoot_left_1.png", NULL);

  player_images[34] = load_bitmap ( "images/character/blindfire_right_1.png", NULL);
  player_images[35] = load_bitmap ( "images/character/blindfire_left_1.png", NULL);

  projectileSprites[0][0] = load_bitmap("images/laser.png", NULL);
  projectileSprites[0][1] = load_bitmap("images/laser.png", NULL);
  projectileSprites[0][2] = load_bitmap("images/laser_hit.png", NULL);


  //HUD images (probably not the best file for it, oh well.)
  statusbar = load_bitmap("images/HUD/statusbar.png", NULL);
  gui_paper = load_bitmap("images/HUD/gui_paper.png", NULL);
  gui_statue = load_bitmap("images/HUD/gui_statue.png", NULL);
  gui_pistol = load_bitmap("images/HUD/pistol.png", NULL);
  gui_mp5 = load_bitmap("images/HUD/mp5.png", NULL);
  gui_ppsh = load_bitmap("images/HUD/ppsh.png", NULL);
  gui_minigun = load_bitmap("images/HUD/minigun.png", NULL);
  gui_remington = load_bitmap("images/HUD/remington.png", NULL);
}

// Load sounds
void player::load_sounds(){
  if(!(walk1 = load_sample("sounds/walk_1.wav"))){
    abort_on_error( "Cannot find sounds/keen_walk_1.wav \n Please check your files and try again");
  }
  if(!(walk2 = load_sample("sounds/walk_2.wav"))){
    abort_on_error( "Cannot find sounds/keen_walk_2.wav \n Please check your files and try again");
  }
  if(!(jump = load_sample("sounds/jump_1.wav"))){
    abort_on_error( "Cannot find sounds/jump_1.wav \n Please check your files and try again");
  }
  if(!(death_fall = load_sample("sounds/death_fall.wav"))){
    abort_on_error( "Cannot find sounds/death_fall.wav \n Please check your files and try again");
  }
  if(!(death_impact = load_sample("sounds/death_impact.wav"))){
    abort_on_error( "Cannot find sounds/death_impact.wav \n Please check your files and try again");
  }
  if(!(getItem = load_sample("sounds/get_item.wav"))){
    abort_on_error( "Cannot find sounds/get_item.wav \n Please check your files and try again");
  }
  if(!(getItem = load_sample("sounds/get_item.wav"))){
    abort_on_error( "Cannot find sounds/get_item.wav \n Please check your files and try again");
  }
  if(!(getBonus = load_sample("sounds/get_bonus.wav"))){
    abort_on_error( "Cannot find sounds/get_bonus.wav \n Please check your files and try again");
  }
  if(!(dryfire = load_sample("sounds/dryfire.wav"))){
    abort_on_error( "Cannot find sounds/dryfire.wav \n Please check your files and try again");
  }
  if(!(Switch = load_sample("sounds/switch.wav"))){
    abort_on_error( "Cannot find sounds/switch.wav \n Please check your files and try again");
  }
  if(!(walk_stone = load_sample("sounds/walk_stone.wav"))){
    abort_on_error( "Cannot find sounds/walk_stone.wav \n Please check your files and try again");
  }
  if(!(glass = load_sample("sounds/glass.wav"))){
    abort_on_error( "Cannot find sounds/glass.wav \n Please check your files and try again");
  }
  if(!(alarm = load_sample("sounds/alarm.wav"))){
    abort_on_error( "Cannot find sounds/alarm.wav \n Please check your files and try again");
  }
  if(!(elevator = load_sample("sounds/elevator.wav"))){
    abort_on_error( "Cannot find sounds/elevator.wav \n Please check your files and try again");
  }
  if(!(wood_smash = load_sample("sounds/wood_smash.wav"))){
    abort_on_error( "Cannot find sounds/wood_smash.wav \n Please check your files and try again");
  }
  if(!(pistol_boxget = load_sample("sounds/pistol_boxget.wav"))){
    abort_on_error( "Cannot find sounds/pistol_boxget.wav \n Please check your files and try again");
  }
  if(!(hurt_fall = load_sample("sounds/hurt_fall.wav"))){
    abort_on_error( "Cannot find sounds/hurt_fall.wav \n Please check your files and try again");
  }
  if(!(death_radioactive = load_sample("sounds/death_radioactive.wav"))){
    abort_on_error( "Cannot find sounds/death_radioactive.wav \n Please check your files and try again");
  }
  if(!(item_energydrink = load_sample("sounds/item_energydrink.wav"))){
    abort_on_error( "Cannot find sounds/item_energydrink.wav \n Please check your files and try again");
  }
  if(!(squeak_mailbox = load_sample("sounds/squeak_mailbox.wav"))){
    abort_on_error( "Cannot find sounds/squeak_mailbox.wav \n Please check your files and try again");
  }
  if(!(squeak_door = load_sample("sounds/squeak_door.wav"))){
    abort_on_error( "Cannot find sounds/squeak_door.wav \n Please check your files and try again");
  }
  if(!(water_splash = load_sample("sounds/water_splash.wav"))){
    abort_on_error( "Cannot find sounds/water_splash.wav \n Please check your files and try again");
  }
  if(!(water_walk = load_sample("sounds/water_walk.wav"))){
    abort_on_error( "Cannot find sounds/water_walk.wav \n Please check your files and try again");
  }
  if(!(weapon_pickup = load_sample("sounds/weapon_pickup.wav"))){
    abort_on_error( "Cannot find sounds/weapon_pickup.wav \n Please check your files and try again");
  }
}

// Return X
int player::getX(){
  return x;
}

// Return Y
int player::getY(){
  return y;
}

// Finished level?
bool player::getFinishLevel(){
  return finishLevel;
}

// Finished level
void player::setFinishLevel(int newFinishLevel){
  finishLevel = newFinishLevel;
}

// Dead?
bool player::getDead(){
  return dead;
}

//Get bullets
vector<projectile>* player::getBullets(){
  return &bullets;
}

//Set dead
void player::setDead(bool newDead){
  dead = newDead;
}

//Draw character
void player::draw(BITMAP* temp, int tile_map_x, int tile_map_y){
  if( !shooting){

        //file_select_ex("Select Image","c:","GIF;JPG",480,100,50);

    // Jumping
    if(!jumping_animation_done){
      if(characterDir == LEFT){
        draw_sprite( temp, player_images[12 + jumping_animation_sequence/2], x - tile_map_x, y - tile_map_y);
      }
      else{
        draw_sprite( temp, player_images[18 + jumping_animation_sequence/2], x - tile_map_x, y - tile_map_y);
      }
    }
    // Jumping or falling
    else if(jumping || canFall){
      if(characterDir == LEFT){
        draw_sprite( temp, player_images[17], x - tile_map_x, y - tile_map_y);
      }
      else{
        draw_sprite( temp, player_images[23], x - tile_map_x, y - tile_map_y);
      }
    }
    // Walking
    else{
      if( height == 0){
        if( player_images[characterDir + walking_animation_sequence/ANIMATION_SPEED] != NULL){
          draw_sprite( temp, player_images[characterDir + walking_animation_sequence/ANIMATION_SPEED], x - tile_map_x, y - tile_map_y);
        }
      }
      // Crouching
      else if(characterDir == RIGHT){
        draw_sprite( temp, player_images[30], x - tile_map_x, y - tile_map_y);
      }
      else if(characterDir == LEFT){
        draw_sprite( temp, player_images[31], x - tile_map_x, y - tile_map_y);
      }
    }
  }
  // Shooting
  else{
    if(characterDir == LEFT){
      if( height == 0){
        draw_sprite( temp, player_images[24], x - tile_map_x, y - tile_map_y);
      }
      else{
        draw_sprite( temp, player_images[33], x - tile_map_x, y - tile_map_y);
      }
    }
    else{
      if( height == 0){
        draw_sprite( temp, player_images[25], x - tile_map_x, y - tile_map_y);
      }
      else{
        draw_sprite( temp, player_images[32], x - tile_map_x, y - tile_map_y);
      }
    }
  }
  //textprintf_ex(temp,pixelart_2,400,50,makecol(255,255,255),makecol(0,0,0),"Dir:%i  Ani:%i  Full:%i",characterDir, walking_animation_sequence, characterDir + walking_animation_sequence/ANIMATION_SPEED);

  //Draw bullets
  for(int i = 0; i < bullets.size(); i++){
    bullets.at(i).draw(temp,tile_map_x, tile_map_y);
  }

  //Draw HUD
  if(!isReadingBlock){
  textprintf_ex(temp,pixelart_2,224,10,makecol(255,255,255),makecol(0,0,0),"%i",stamina );
  textprintf_ex(temp,pixelart_2,224,50,makecol(255,255,255),makecol(0,0,0),"%i",health );
  if(inLiquid)textprintf_ex(temp,pixelart_2,224,85,makecol(255,255,255),makecol(0,0,0),"%i",oxygen );

  if(currentWeapon!=0){
    if(weapon[currentWeapon].ammunition>9)textprintf_ex(temp,munro_large,480,70,makecol(255,255,255),makecol(0,0,-1),"%i",weapon[currentWeapon].ammunition);
    if(weapon[currentWeapon].ammunition<10)textprintf_ex(temp,munro_large,480,70,makecol(255,255,255),makecol(0,0,-1),"0%i",weapon[currentWeapon].ammunition);
    if(weapon[currentWeapon].magazine>9)textprintf_ex(temp,munro_large,510,70,makecol(255,255,255),makecol(0,0,-1),"/%i",weapon[currentWeapon].magazine);
    if(weapon[currentWeapon].magazine<10)textprintf_ex(temp,munro_large,510,70,makecol(255,255,255),makecol(0,0,-1),"/0%i",weapon[currentWeapon].magazine);
  }
  textprintf_ex(temp,pixelart,5,180,makecol(255,255,255),makecol(0,0,0),"Deathcount:%i",deathcount);
  textprintf_ex(temp,pixelart,5,200,makecol(255,255,255),makecol(0,0,0),"Weapon:%i",currentWeapon );
  if(isTalkingToNpc){
    if(npc_ID==0)textprintf_ex(temp,munro_large,20,SCREEN_H-62,makecol(255,255,255),makecol(0,0,0),"Hi! Head on inside, Gerald is waiting. Good luck!");
    if(npc_ID==1){
      textprintf_ex(temp,munro_large,20,SCREEN_H-108,makecol(255,255,255),makecol(0,0,0),"Hey man, I've been hearing weird noises from the basement, you should");
      textprintf_ex(temp,munro_large,20,SCREEN_H-62,makecol(255,255,255),makecol(0,0,0),"go check it out!");
      }
    }
  draw_sprite(temp,statusbar, 10, 10);
  draw_sprite(temp,statusbar, 10, 45);
  if(inLiquid)draw_sprite(temp,statusbar, 10, 80);
  if(currentWeapon==1)draw_sprite(temp,gui_pistol, 280, 10);
  if(currentWeapon==2)draw_sprite(temp,gui_mp5, 280, 10);
  if(currentWeapon==3)draw_sprite(temp,gui_ppsh, 280, 10);
  if(currentWeapon==4)draw_sprite(temp,gui_minigun, 280, 10);
  if(currentWeapon==5)draw_sprite(temp,gui_remington, 280, 10);
  rectfill(temp, 14, 14, 14+((stamina*2)), 33, (255,255,(stamina*2)+55));
  rectfill(temp, 14, 49, 14+(health*2), 68, makecol((health*2)+55,0,0));
  if(inLiquid)rectfill(temp, 14, 84, 14+(oxygen*2), 103, makecol((oxygen*2)+55,(oxygen*2)+55,(oxygen*2)+55));
  }

  if(isReadingBlock){
    if(read_ID==0){
        draw_sprite(temp,gui_paper, 0, 0);
        textprintf_ex(temp,munro_large,200,100,makecol(0,0,0),makecol(0,0,-1),"Look! This page has words!");

    }
    if(read_ID==1){
      draw_sprite(temp,gui_statue, 0, 0);
      textprintf_ex(temp,munro_large,400,600,makecol(0,0,0),makecol(0,0,-1),"The statue has been liberated!");

      }
    }




  if(!canFall){
    if(fallheight>15){
        health -= fallheight*2;
        if(health>0)play_sample(hurt_fall,255,125,random(750,1250),0);
        if(health<1)play_sample(death_impact,255,125,1000,0);
    }
    fallheight=0;
  }



}
 // Spawn
void player::spawncommand(tileMap *newMap){
  stamina=100;
  for(int i = 0; i < newMap -> mapTiles.size(); i++){
    if(newMap -> mapTiles.at(i).getType() == tile_spawn_player){
      x = newMap -> mapTiles.at(i).getX();
      y = newMap -> mapTiles.at(i).getY();
    }
  }

  bool goodLocation = false;

  while( goodLocation == false){
    // Scroll Map to location
    if(y - newMap -> y < 480 && newMap -> y > 0){
      newMap -> y -= 1;
    }
    else if(y - newMap -> y > 480 && newMap -> y < newMap -> height * 64 -  960){
      newMap -> y += 1;
    }
    else if(x - newMap -> x < 640 && newMap -> x > 0){
      newMap -> x -= 1;
    }
    else if(x - newMap -> x > 640 && newMap -> x < newMap -> width * 64 - 1280){
      newMap -> x += 1;
    }
    else{
      goodLocation = true;
    }
  }
}

//  Movement
void player::update(tileMap *newMap){



  // Scroll Map
  if(y - newMap -> y < 400 && newMap -> y > 0){
    newMap -> y -= 16;
  }
  if(y - newMap -> y > 550 && newMap -> y < newMap -> height * 64 -  960){
    newMap -> y += 16;
  }
  if(x - newMap -> x < 500 && newMap -> x > 0){
     if( isSprinting && stamina > 0){
        newMap -> x -= 16;
     }
     else if( isCrouching){
        newMap -> x -= 8;
     }
     else {
        newMap -> x -= 8;
     }
  }

  if(x - newMap -> x > 480 && newMap -> x < newMap -> width * 64 - 1280){
     if( isSprinting){
        newMap -> x += 16;
     }
     else if( isCrouching && stamina > 0){
        newMap -> x += 8;
     }
     else {
        newMap -> x += 8;
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
  bool headInLiquid = false;
  bool canStopCrouch = true;
  bool canCrouchLeft =  true;
  bool canCrouchRight = true;
  bool canSwimDown = true;
  inLiquid = false;



  //Check for collision
  for(int i = 0; i < newMap -> mapTiles.size(); i++){
    if(collisionAny(x - 64*2, x + 64*2, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 128*2, y + 128*2, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
      if(newMap -> mapTiles.at(i).getAttribute() == solid){
        if(collisionAny(x - 4, x + 60, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + height + 16, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           collisionLeft(x - 4, x + 60, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
          canMoveLeft = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == solid){
        if(collisionAny(x + 4, x + 68, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + height + 16, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           collisionRight(x + 4, x + 68, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
          canMoveRight = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == solid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y, newMap -> mapTiles.at(i).getY(),newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canClimbUp = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == climb){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canClimbUp2 = true;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == solid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canClimbDown = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == liquid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canSwimDown = false;
        }
      }

      if(newMap -> mapTiles.at(i).getAttribute() == climb){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canClimbDown2 = true;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() != gas && newMap -> mapTiles.at(i).getAttribute() != liquid && newMap -> mapTiles.at(i).getAttribute() != interactive && newMap -> mapTiles.at(i).getAttribute() != cover){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canJump = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == solid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + height - 16, y + height - 16, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          canStopCrouch = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() != gas && newMap -> mapTiles.at(i).getAttribute() != liquid && newMap -> mapTiles.at(i).getAttribute() != climb && newMap -> mapTiles.at(i).getAttribute() != interactive){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight(), y, y + 144) &&
        collisionTop(newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64, y + yVelocity, y + 144 + yVelocity + 16)){
          canJumpUp = false;
        }
      }
      if(newMap -> mapTiles.at(i).getAttribute() == liquid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          inLiquid = true;
        }
      }
    if(newMap -> mapTiles.at(i).getAttribute() == liquid){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 20, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          headInLiquid = true;
        }
      }

      if(newMap -> mapTiles.at(i).getAttribute() == cover){
        if(collisionAny(x - 4, x + 60, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + height + 16, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           collisionLeft(x - 4, x + 60, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
          canCrouchLeft = false;
        }
      }

      if(newMap -> mapTiles.at(i).getAttribute() == cover){
        if(collisionAny(x + 4, x + 8, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + height + 16, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           collisionRight(x + 4, x + 8, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth())){
          canCrouchRight = false;
        }
      }
      // Pick up Items
      if(newMap -> mapTiles.at(i).getAttribute() == item){
        if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16 + height, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          if(newMap -> mapTiles.at(i).getType() == tile_energydrink){
            play_sample(item_energydrink,255,125,1000,0);
            if(stamina-50>50){
              staminaBoost=true;
              stamina=100;
              newMap -> mapTiles.at(i).setType(0);
            }
            else{
              staminaBoost=true;
              stamina+=50;
              newMap -> mapTiles.at(i).setType(0);
            }
          }

          int weaponAquired = false;

          if(newMap -> mapTiles.at(i).getType() == tile_pistol)weaponAquired=1;
          if(newMap -> mapTiles.at(i).getType() == tile_mp5)weaponAquired=2;
          if(newMap -> mapTiles.at(i).getType() == tile_ppsh)weaponAquired=3;
          if(newMap -> mapTiles.at(i).getType() == tile_minigun)weaponAquired=4;
          if(newMap -> mapTiles.at(i).getType() == tile_remington)weaponAquired=5;
          if(weaponAquired!=0){
           play_sample(weapon_pickup,255,125,1000,0);
           if(weapon[weaponAquired].magazine==0)weapon[weaponAquired].magazine+=weapon[weaponAquired].magazineSize;
           else weapon[weaponAquired].ammunition+=weapon[weaponAquired].magazineSize;
           weapon[weaponAquired].aquired=true;
           newMap -> mapTiles.at(i).setType(0);
          }


          if(newMap -> mapTiles.at(i).getType() == tile_pistol_magazine){
            weapon[1].ammunition+=8;
            newMap -> mapTiles.at(i).setType(0);
          }
          if(newMap -> mapTiles.at(i).getType() == tile_pistol_box){
            weapon[1].ammunition+=50;
            play_sample(pistol_boxget,255,125,1000,0);
            newMap -> mapTiles.at(i).setType(0);
          }
          if(newMap -> mapTiles.at(i).getType() == tile_medpack){
            health+=20;
            if(health>100)health=100;
            newMap -> mapTiles.at(i).setType(0);
          }
        }
      }
    }

    //NPC

    if(key[KEY_E] || joy[0].button[2].b){

     // particle newParticle( x + random( 0, 40), y + random( 0, 40), color, -2, 2, -2, 2, CIRCLE, 1);
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
        if(newMap -> mapTiles.at(i).getAttribute() == npc){
            npc_ID = newMap -> mapTiles.at(i).getType()-300;
            isTalkingToNpc=true;
            }
      }
    }else isTalkingToNpc=false;

     //Reading blocks
     if(key[KEY_E] || joy[0].button[2].b){
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
        if(newMap -> mapTiles.at(i).getAttribute() == readable){
            read_ID = newMap -> mapTiles.at(i).getType()-400;
            isReadingBlock=true;
        }
      }
    }else isReadingBlock=false;





    //Interactive
    if(key[KEY_E] || joy[0].button[2].b){
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
        if(newMap -> mapTiles.at(i).getAttribute() == interactive){
          //Flicking switch
          if(newMap -> mapTiles.at(i).getType() == tile_generator_off  && switch_loop>20){newMap -> mapTiles.at(i).setType(44); switch_loop=0;play_sample(Switch,255,125,1000,0); switch_direction=true; switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_generator_on && switch_loop>20){newMap -> mapTiles.at(i).setType(45); switch_loop=0;play_sample(Switch,255,125,1000,0); switch_direction=false; switch_frame=0;}
          //Smashing lights
          if(newMap -> mapTiles.at(i).getType() == tile_light_cage_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(47); switch_loop=0;play_sample(glass,255,125,random(500,1500),0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_light_cage_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(48); switch_loop=0;play_sample(glass,255,125,random(500,1500),0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_light_cage_3 && switch_loop>10){newMap -> mapTiles.at(i).setType(49); switch_loop=0;play_sample(glass,255,125,random(500,1500),0); switch_frame=0;}
          //Use elevator
          if(newMap -> mapTiles.at(i).getType() == tile_elevator_1  && switch_loop>20){newMap -> mapTiles.at(i).setType(51); switch_loop=0;play_sample(elevator,255,125,1000,0); elevator_direction=true; switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_elevator_2  && switch_loop>20){newMap -> mapTiles.at(i).setType(51); switch_loop=0;play_sample(elevator,255,125,1000,0); elevator_direction=true; switch_frame=0;}
          //Smashing box
          if(newMap -> mapTiles.at(i).getType() == tile_crate1_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(84); switch_loop=0;play_sample(wood_smash,255,125,random(500,1500),0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_crate1_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(85); switch_loop=0;play_sample(wood_smash,255,125,random(500,1500),0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_crate1_3 && switch_loop>10){newMap -> mapTiles.at(i).setType(86); switch_loop=0;play_sample(wood_smash,255,125,random(500,1500),0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_crate1_4 && switch_loop>10){newMap -> mapTiles.at(i).setType(87); switch_loop=0;play_sample(wood_smash,255,125,random(500,1500),0); switch_frame=0;}
          //Door
          if(newMap -> mapTiles.at(i).getType() == tile_brick_door_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(108); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_brick_door_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(107); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_brown_door_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(118); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_brown_door_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(117); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_door_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(120); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_door_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(119); switch_loop=0;play_sample(squeak_door,255,125,1000,0); switch_frame=0;}
          //Mailbox
          if(newMap -> mapTiles.at(i).getType() == tile_mailbox_1 && switch_loop>10){newMap -> mapTiles.at(i).setType(6); switch_loop=0;play_sample(squeak_mailbox,255,125,1000,0); switch_frame=0;}
          if(newMap -> mapTiles.at(i).getType() == tile_mailbox_2 && switch_loop>10){newMap -> mapTiles.at(i).setType(5); switch_loop=0;play_sample(squeak_mailbox,255,125,1000,0); switch_frame=0;}
        }
      }
    }
      // Level Switching
      if(key[KEY_Q] || joy[0].button[3].b){
        if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          if(newMap -> mapTiles.at(i).getAttribute() == interactive){
            if(newMap -> mapTiles.at(i).getType() == tile_elevator_33 || newMap -> mapTiles.at(i).getType() == tile_brick_door_2 || newMap -> mapTiles.at(i).getType() == tile_brown_door_2){
                finishLevel = true;
                if(level==1)newMap -> load("data/levels/level_02");
                if(level==2)newMap -> load("data/levels/level_03");
                if(level==3)newMap -> load("data/levels/level_04");
                if(level==4)newMap -> load("data/levels/level_05");
                if(level==5)newMap -> load("data/levels/level_06");
                if(level==6)newMap -> load("data/levels/level_07");
                if(level==7)newMap -> load("data/levels/level_08");
                if(level==8)newMap -> load("data/levels/level_09");
                if(level==9)newMap -> load("data/levels/level_10");
                if(level==10)newMap -> load("data/levels/level_11");
                level++;

                spawncommand(newMap);
          }
        }
      }
    }
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
          if(newMap -> mapTiles.at(i).getAttribute() == levelend){
                finishLevel = true;
                if(level==1)newMap -> load("data/levels/level_02");
                if(level==2)newMap -> load("data/levels/level_03");
                if(level==3)newMap -> load("data/levels/level_04");
                if(level==4)newMap -> load("data/levels/level_05");
                if(level==5)newMap -> load("data/levels/level_06");
                if(level==6)newMap -> load("data/levels/level_07");
                if(level==7)newMap -> load("data/levels/level_08");
                if(level==8)newMap -> load("data/levels/level_09");
                if(level==9)newMap -> load("data/levels/level_10");
                if(level==10)newMap -> load("data/levels/level_11");
                level++;

                spawncommand(newMap);

      }
    }
    //Frame moving up
    if(switch_direction){
      if(switch_frame>3)if(newMap -> mapTiles.at(i).getType() == tile_generator_2){newMap -> mapTiles.at(i).setType(43); switch_frame=0;}
      if(switch_frame>3)if(newMap -> mapTiles.at(i).getType() == tile_generator_1){newMap -> mapTiles.at(i).setType(45); switch_frame=0;}
    }
    if(!switch_direction){
      if(switch_frame>3)if(newMap -> mapTiles.at(i).getType() == tile_generator_2){newMap -> mapTiles.at(i).setType(44); switch_frame=0;}
      if(switch_frame>3)if(newMap -> mapTiles.at(i).getType() == tile_generator_1){newMap -> mapTiles.at(i).setType(25); switch_frame=0;}
    }

    // Elevator opening
    if(elevator_direction){
      if(switch_frame > 200 && !elevator_called){
        if(newMap -> mapTiles.at(i).getType() == tile_elevator_2){
          newMap -> mapTiles.at(i).setType(52);
          switch_frame=0;
          elevator_called=true;
        }
      }
      if(switch_frame>3){
        if(newMap -> mapTiles.at(i).getType() == tile_elevator_2 && elevator_called){
          newMap -> mapTiles.at(i).setType(52);
          switch_frame=0;
        }
        if(newMap -> mapTiles.at(i).getType() >= tile_elevator_3 && newMap -> mapTiles.at(i).getType() <= tile_elevator_32){
          newMap -> mapTiles.at(i).setType(newMap -> mapTiles.at(i).getType() + 1);
          switch_frame=0;
        }
      }
    }

    //Footstep material
    if(newMap -> mapTiles.at(i).getAttribute() == solid){
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y, y + 129, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
        if(newMap -> mapTiles.at(i).getType() == tile_cement_1)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_2)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_3)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_4)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_5)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_6)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_7)material=1;
        if(newMap -> mapTiles.at(i).getType() == tile_cement_8)material=1;
      }
    }
  }

  //Switch loop and frame
  switch_loop++;
  switch_frame++;

  //Check for dangers
  for(int i = 0; i < newMap -> mapTiles.size(); i++){
    //Die
    if(newMap -> mapTiles.at(i).getAttribute() == harmful){
      if(collisionAny(x + 18, x + 46, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y-16 + height, y + 128, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64)){
        if(newMap -> mapTiles.at(i).getType() == 97)play_sample(death_radioactive,122,125,1000,0);
        else if(newMap -> mapTiles.at(i).getType() == 98)play_sample(death_radioactive,122,125,1000,0);
        else if(newMap -> mapTiles.at(i).getType() == 99)play_sample(death_radioactive,122,125,1000,0);
        else if(newMap -> mapTiles.at(i).getType() == 100)play_sample(death_radioactive,122,125,1000,0);
        dead = true;
      }
    }
    if(x > newMap -> width*64 || x < 0 || y > newMap -> height*64){
      play_sample(death_fall,122,125,1000,0);
      dead = true;
      fallheight = 0;
    }
  }

  //Move up
  if(key[KEY_W] || joy[0].stick[0].axis[1].d1 ){
    characterDir = UP;
    if(canClimbUp2 && canClimbUp){
      if(!isSprinting){
         y -= 8;
         walking_animation_sequence++;
      }
      else{
        y -= 16;
        walking_animation_sequence++;
        stamina--;
      }
    }
  }

  //Move down
  if(key[KEY_S] || joy[0].stick[0].axis[1].d2){
    characterDir = UP;
    if(canClimbDown2 && canClimbDown){
      if(!isSprinting){
         y += 8;
         walking_animation_sequence++;
      }
      else if(stamina>0){
        y += 16;
        walking_animation_sequence++;
        stamina--;
      }
      else if(stamina=0){
        y += 8;
        walking_animation_sequence++;
      }
    }if(canSwimDown && inLiquid){
       y+=7;
    }
  }

  //Move right
  if(key[KEY_D] || joy[0].stick[0].axis[0].d2 || key[KEY_RIGHT]){
    if(!key[KEY_A] && jumping_animation_done && x < newMap -> width*64){
        if(inLiquid)play_sample(water_walk,255,125,1000,0);
        characterDir = RIGHT;
        if(canMoveRight){
            if(isSprinting && stamina>0 && !isCrouching){x += 16; stamina--;}
        else if(isCrouching && canCrouchRight)x += 2;
        else if(!isCrouching)x +=8;
        walking_animation_sequence++;
        if(walking_animation_sequence == 1*ANIMATION_SPEED && !canFall && !jumping){
            if(!isCrouching){
            if(!inLiquid){
                play_sample(walk_stone,255,125,1000,0);

            }else play_sample(water_walk,255,125,random(750,1250),0);
          }
        }
      }
    }
  }

  //Move left
  if(key[KEY_A] || joy[0].stick[0].axis[0].d1 || key[KEY_LEFT]){
    if(!key[KEY_D] && jumping_animation_done && x > 0 || joy[0].stick[0].axis[0].d2 && jumping_animation_done && x > 0  ){

        characterDir = LEFT;
        if(canMoveLeft){
            if(isSprinting && stamina>0 && !isCrouching){x -= 16; stamina--;}
        else if(isCrouching && canCrouchLeft)x -= 2;
        else if(!isCrouching)x -=8;
        walking_animation_sequence++;
        if(walking_animation_sequence == 1*ANIMATION_SPEED && !canFall && !jumping){
            if(!isCrouching){
            if(!inLiquid){
                play_sample(walk_stone,255,125,1000,0);

            }else play_sample(water_walk,255,125,random(750,1250),0);
          }
        }
      }
    }
  }
  canFall = true;
  bool smoothFall = false;

  //Falling (calculated seperately to ensure collision accurate)
  for(int i = 0; i < newMap -> mapTiles.size(); i++){
    if(collisionAny(x - 64*2, x + 64*2, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y - 128*2, y + 128*2, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight())){
      if(newMap -> mapTiles.at(i).getAttribute() == solid || newMap -> mapTiles.at(i).getAttribute() == climb){
        if(collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           collisionTop(y, y + 144, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 64)){
          canFall = false;
          if(!collisionAny(x + 16, x + 48, newMap -> mapTiles.at(i).getX(), newMap -> mapTiles.at(i).getX() + newMap -> mapTiles.at(i).getWidth(), y + 16, y + 129, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight()) &&
           !collisionTop(y + 16, y + 129, newMap -> mapTiles.at(i).getY(), newMap -> mapTiles.at(i).getY() + newMap -> mapTiles.at(i).getHeight() + 65)){
            smoothFall = true;
          }
        }
      }
    }
  }
  //GUNS!!!!!!
  if(weapon[1].aquired)
  //WTF happened here ^^^^^^^^

  //Stamina
  if(stamina<100 && staminaLoop>10){
    if(!jumping){
      stamina++;
    }
    staminaLoop=0;
  }
  staminaLoop++;
  if(isCrouching)stamina++;

  if(stamina<0)
    stamina=0;
  if(stamina>100)
    stamina=100;

  //Fall
  if(canFall && !jumping){
    if(inLiquid){
      y += 16;
      fallheight++;
    }
    else{
      y += 16;
      fallheight++;
    }
  }
  //Sink
  if(inLiquid && canSwimDown)
    y+=2;

  if(key[KEY_LSHIFT] || joy[0].button[8].b){
    isSprinting=true;
  }else isSprinting=false;
  //Smooth falling
  if(smoothFall){
    y += 1;
  }
  //Oxygen
  if(headInLiquid && oxygen>0){
    oxygenHarm++;
  }
  if(oxygenHarm>9){
    oxygenHarm=0;
    oxygen--;
  }
  if(!headInLiquid && oxygen<100){
    oxygen+=5;
  }
  if(oxygen<1) health--;

  if(oxygen>100)oxygen=100;

  //Fall damage
  if(!canFall){
    if(fallheight>10 && !inLiquid){
      health -= fallheight*2;

      if(health>0)
        play_sample(hurt_fall,255,125,random(750,1250),0);
      if(health<1)
        play_sample(death_impact,255,125,1000,0);
    }
    if(fallheight>5 && inLiquid)if(inLiquid)play_sample(water_splash,255,125,1000,0);
    fallheight=0;
  }
  //Death
  if(health<1){
    dead = true;
  }
  if(dead){
    deathcount++;
    spawncommand(newMap);
    health = 100;
  }

  //Jump over cover
  if(isCrouching && !canCrouchRight && key[KEY_C]){
    x+=64;
  }

  //Snap to cover
  if(key[KEY_Z]){
    moving_to_cover = true;
    if(characterDir = RIGHT){
      if(canCrouchRight && canMoveRight && moving_to_cover){
        x+=4;
      }
      else if(!canCrouchRight || !canMoveRight){
        moving_to_cover=false;
      }
    }
  }
  //Jumping
  if(jumping && canJumpUp && !inLiquid){
    if(canFall || jump_height > 0 ){
      y -= yVelocity;
    }

    if(jump_height <= 0){
      if(yVelocity > -16){
        yVelocity -= 2;
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


  //Crouch
  if(isCrouching){
    height = 64;
  }else if( canStopCrouch){
    height=0;
  }

  if(key[KEY_LCONTROL] || joy[0].button[4].b){
    isCrouching=true;
  }else if(canStopCrouch) isCrouching=false;

  //Jump
  if(joy[0].button[0].b || key[KEY_SPACE]){
    if(!isCrouching){
       if(inLiquid){
           y -= 8;
        }
        if(!canFall && canJump && !jumping && jumping_animation_done){
        yVelocity = 16;
        play_sample(jump,255,125,1000,0);
        jumping_animation_done = false;
        jump_height = 0;
       }
    }
  }

  //Increase jump animation sequence
  if(!jumping_animation_done){
    jumping_animation_sequence++;
    if(key[KEY_SPACE] || joy[0].button[0].b ){
      if(jumping_animation_sequence < 4){
        jump_height=6;
      }
      else if(jumping_animation_sequence < 11){
        jump_height=12;
      }
      else if(jumping_animation_sequence < 12){
        jump_height = 18;
      }
    }
    if(jumping_animation_sequence > 10){
      jumping_animation_sequence = 0;
      jumping_animation_done = true;
      jumping = true;
    }
  }
  // Reset animation sequence
  if(walking_animation_sequence == ANIMATION_SPEED * 4){
    walking_animation_sequence = 0;
  }

  // Prevents getting stuck through an animation
  else if(!key[KEY_LEFT] && !key[KEY_RIGHT] && !key[KEY_A] && !key[KEY_D]){
    walking_animation_sequence = 0;
    stop_sample(walk_stone);
  }

  // Not shooting anymore
  if(shooting){
    shooting_animation_sequence++;
    if( shooting_animation_sequence > weapon[currentWeapon].rateOfFire){
      shooting = false;
      shooting_animation_sequence = 0;
    }
  }
  //Change currentWeapon
  if(key[KEY_TILDE])currentWeapon=0;
  if(key[KEY_1] && weapon[1].aquired)currentWeapon=1;
  if(key[KEY_2] && weapon[2].aquired)currentWeapon=2;
  if(key[KEY_3] && weapon[3].aquired)currentWeapon=3;
  if(key[KEY_4] && weapon[4].aquired)currentWeapon=4;
  if(key[KEY_5] && weapon[5].aquired)currentWeapon=5;
  if(key[KEY_6] && weapon[6].aquired)currentWeapon=6;
  if(key[KEY_7] && weapon[7].aquired)currentWeapon=7;
  if(key[KEY_8] && weapon[8].aquired)currentWeapon=8;
  if(key[KEY_9] && weapon[9].aquired)currentWeapon=9;

  if(joy[0].stick[1].axis[4].d1){

  }
  //Harm player
  if(key[KEY_H])health--;


  //Spawns
  if(key[KEY_F]){
    finishLevel = true;
    newMap -> load("data/levels/level_02");
    spawncommand(newMap);
  }
  if(!initial_spawn){
   spawncommand(newMap);
   initial_spawn=true;
  }

  //Shoot currentWeapon
  if(joy[0].stick[0].axis[2].d1 && !shooting && currentWeapon!=0 || !shooting && key[KEY_ENTER]&& currentWeapon!=0){
    if(weapon[currentWeapon].rateOfFire==-1 && !triggerReleased){
        canShoot=false;
    }else canShoot=true;
    triggerReleased=false;
    if(weapon[currentWeapon].magazine > 0 && canShoot){
      int bulletSpeed;
      int bulletDirection = 1;
      int bulletHeight = 63;
      bulletSpeed=weapon[currentWeapon].speed;
      if(height != 0)bulletHeight = 102;
      if(characterDir == LEFT){
        bulletDirection = -1;
      }
      if(weapon[currentWeapon].bulletsFired==1){
        projectile newBullet( 0, x + 30, y + bulletHeight, bulletSpeed * bulletDirection);
        bullets.push_back(newBullet);
      }
      else if(weapon[currentWeapon].bulletsFired!=1){
        if(height==0){
          for(int i = 0; i < weapon[currentWeapon].bulletsFired;  i++){
            projectile newBullet( 0, x + 30, y + bulletHeight-(i*10), bulletSpeed * bulletDirection);
            bullets.push_back(newBullet);
          }
        }
      }
      weapon[currentWeapon].magazine--;
    }
    else if(canShoot) play_sample(dryfire,255,125,1000,0);

    shooting = true;
  }
  if(!joy[0].stick[0].axis[2].d1 && !key[KEY_ENTER]){
    triggerReleased=true;
  }
  if(weapon[currentWeapon].magazine==0)reloadTicks++;

  if(reloadTicks>=weapon[currentWeapon].reloadSpeed){
    reloadTicks=0;
    if(weapon[currentWeapon].ammunition >= weapon[currentWeapon].magazineSize){
      weapon[currentWeapon].ammunition -= weapon[currentWeapon].magazineSize;
      weapon[currentWeapon].magazine = weapon[currentWeapon].magazineSize;
    }
    else{
      weapon[currentWeapon].ammunition = weapon[currentWeapon].magazine;
      weapon[currentWeapon].ammunition = 0;
    }
  }

  // Update bullets
  for(int i = 0; i < bullets.size(); i++){
    bullets.at(i).update();
    if((bullets.at(i).getContact(newMap) && bullets.at(i).getContactFrameCounter() == 10) || bullets.at(i).getContact()){
      bullets.erase(bullets.begin() + i);
    }
  }
    //ESC key handler
    //Yes Allan, its in the player class. Deal with it.

    if(key[KEY_ESC]){
        exit_menu_open=true;
    }
}

player::~player(){
  bullets.clear();

  for(int i = 0; i < 26; i++){
		if(player_images[i]){
			destroy_bitmap(player_images[i]);
		}
	}
  destroy_bitmap( statusbar);

  destroy_sample( walk1);
  destroy_sample( walk2);
  destroy_sample( jump);
  destroy_sample( death_fall);
  destroy_sample( death_impact);
  destroy_sample( getItem);
  destroy_sample( getBonus);

  destroy_sample( dryfire);
  destroy_sample( Switch);
  destroy_sample( walk_stone);
  destroy_sample( glass);
  destroy_sample( alarm);
  destroy_sample( elevator);
  destroy_sample( wood_smash);
  destroy_sample( pistol_boxget);
}
