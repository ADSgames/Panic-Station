#include "tile.h"

tile::tile(int newType){
  setType(newType);
}

//Getters/ setters
int tile::getX(){
  return x;
}
int tile::getY(){
  return y;
}
int tile::getWidth(){
  return width;
}
int tile::getHeight(){
  return height;
}

void tile::setX(int newX){
  x = newX;
}
void tile::setY(int newY){
  y = newY;
}
int tile::getType(){
  return type;
}
int tile::getAttribute(){
  return attribute;
}
BITMAP* tile::getImage(){
  return images[0];
}

//Set type
void tile::setType(int newType){
  type = newType;

  // Sets imagses
  if(tileSprites[type][1] != NULL){
    setImagesAnimated(tileSprites[type][0], tileSprites[type][1], tileSprites[type][2], tileSprites[type][3]);
  }
  else{
    setImages(tileSprites[type][0]);
  }

  // Fronts
  if(type == tile_air){
    attribute = gas;
  }
  else if(type == tile_medpack){
    attribute = item;
  }
  else if(type == tile_grass_1){
    attribute = solid;
  }
  else if(type == tile_mailbox_1){
    attribute = interactive;
  }
  else if(type == tile_mailbox_2){
    attribute = interactive;
  }
  else if(type == tile_asphalt_grass){
    attribute = solid;
  }

  else if(type == tile_id){
    attribute = gas;
  }
  else if(type == tile_old_vorticon){
    attribute = gas;
  }
  else if(type == tile_asdf){
    attribute = solid;
  }
  else if(type == tile_cement_1){
    attribute = solid;
  }
  else if(type == tile_cement_2){
    attribute = solid;
  }
  else if(type == tile_cement_3){
    attribute = solid;
  }
  else if(type == tile_cement_4){
    attribute = solid;
  }
  else if(type == tile_cement_5){
    attribute = solid;
  }
  else if(type == tile_cement_6){
    attribute = solid;
  }
  else if(type == tile_cement_7){
    attribute = solid;
  }
  else if(type == tile_cement_8){
    attribute = solid;
  }
  else if(type == tile_pipe_10){
    attribute = climb;
  }
  else if(type == tile_pipe_11){
    attribute = climb;
  }
  else if(type == tile_pipe_12){
    attribute = climb;
  }
  else if(type == tile_pipe_13){
    attribute = climb;
  }
  else if(type == tile_pipe_14){
    attribute = climb;
  }
  else if(type == tile_pipe_15){
    attribute = climb;
  }
  else if(type == tile_generator_off){
    attribute = interactive;
  }
  else if(type == tile_generator_on){
    attribute = interactive;
  }
  else if(type == tile_energydrink){
    attribute = item;
  }
  else if(type == tile_ammo_pistol){
    attribute = item;
  }
  else if(type == tile_light_cage_1){
    attribute = interactive;
  }
  else if(type == tile_light_cage_2){
    attribute = interactive;
  }
  else if(type == tile_light_cage_3){
    attribute = interactive;
  }
  else if(type == tile_light_cage_4){
    attribute = interactive;
  }
  else if(type == tile_elevator_control){
    attribute = interactive;
  }
  else if(type == tile_elevator_1){
    attribute = interactive;
  }
  else if(type == tile_elevator_2){
    attribute = interactive;
  }
  else if(type == tile_elevator_33){
    attribute = interactive;
  }
  else if(type == tile_crate1_1){
    attribute = interactive;
  }
  else if(type == tile_crate1_2){
    attribute = interactive;
  }
  else if(type == tile_crate1_3){
    attribute = interactive;
  }
  else if(type == tile_crate1_4){
    attribute = interactive;
  }
  else if(type == tile_crate1_5){
    attribute = interactive;
  }
  else if(type == tile_pistol_magazine){
    attribute = item;
  }
  else if(type == tile_pistol_box){
    attribute = item;
  }
  else if(type == tile_cover_1){
    attribute = cover;
  }
  else if(type == tile_cement_radioactive_1){
    attribute = harmful;
  }
  else if(type == tile_cement_radioactive_2){
    attribute = harmful;
  }
  else if(type == tile_cement_radioactive_3){
    attribute = harmful;
  }
  else if(type == tile_cement_radioactive_4){
    attribute = harmful;
  }
  else if(type == tile_roof_1){
    attribute = solid;
  }
  else if(type == tile_roof_2){
    attribute = solid;
  }
  else if(type == tile_roof_3){
    attribute = solid;
  }
  else if(type == tile_roof_4){
    attribute = solid;
  }
  else if(type == tile_brick_1){
    attribute = solid;
  }
  else if(type == tile_brick_door_1){
    attribute = interactive;
  }
  else if(type == tile_brick_door_2){
    attribute = interactive;
  }
  else if(type == tile_brown_door_1){
    attribute = interactive;
  }
  else if(type == tile_brown_door_2){
    attribute = interactive;
  }
  else if(type == tile_door_1){
    attribute = interactive;
  }
  else if(type == tile_door_2){
    attribute = interactive;
  }
  else if(type == tile_brick_1){
    attribute = solid;
  }
  else if(type == tile_cement_wood){
    attribute = solid;
  }
  else if(type == tile_water){
    attribute = liquid;
  }
  else if(type == tile_water_cement_left_1){
    attribute = liquid;
  }
  else if(type == tile_water_cement_left_2){
    attribute = liquid;
  }
  else if(type == tile_water_cement_left_3){
    attribute = liquid;
  }
  else if(type == tile_water_cement_right_1){
    attribute = liquid;
  }
  else if(type == tile_water_cement_right_2){
    attribute = liquid;
  }
  else if(type == tile_water_cement_right_3){
    attribute = liquid;
  }
  else if(type == tile_water_cement_middle){
    attribute = liquid;
  }
  else if(type == tile_dirt){
    attribute = solid;
  }
  else if(type == tile_grass_dirt){
    attribute = solid;
  }
  else if(type == tile_grass_dirt){
    attribute = solid;
  }
  else if(type == tile_pistol){
    attribute = item;
  }
  else if(type == tile_mp5){
    attribute = item;
  }
  else if(type == tile_ppsh){
    attribute = item;
  }
  else if(type == tile_minigun){
    attribute = item;
  }
  else if(type == tile_remington){
    attribute = item;
  }
  else if(type == tile_ammo_mp5){
    attribute = item;
  }
  else if(type == tile_ammo_remington){
    attribute = item;
  }
  else if(type == tile_ammo_ppsh){
    attribute = item;
  }
  else if(type == tile_ammo_minigun){
    attribute = item;
  }
//NPC's
  else if(type == tile_npc_allan){
    attribute = npc;
  }
  else if(type == tile_npc_gerald){
    attribute = npc;
  }
//Readable blocks
  else if(type == tile_readable_paper){
    attribute = readable;
  }
  else if(type == tile_readable_statue){
    attribute = readable;
  }

//SPAWN BLOCKS
  else if(type == tile_spawn_player){
    attribute = spawn;
  }
  else if(type == tile_spawn_mutant){
    attribute = spawn;
  }
//Level end block

  else if(type == tile_teleporter){
    attribute = levelend;
  }

  else{
    attribute = gas;
  }
}

//Set tiles images
void tile::setImagesAnimated(BITMAP* image1, BITMAP* image2, BITMAP* image3, BITMAP* image4){
  images[0] = image1;
  images[1] = image2;
  images[2] = image3;
  images[3] = image4;
  animated = true;

  if(images[0] != NULL){
    width = images[0] -> w;
    height = images[0] -> h;
  }
}

//Set tiles images
void tile::setImages(BITMAP* image1){
  images[0] = image1;
  animated = false;

  if(images[0] != NULL){
    width = images[0] -> w;
    height = images[0] -> h;
  }
}

//Draw tile
void tile::draw_tile(BITMAP* tempSprite, int xOffset, int yOffset, int frame){
  if(images[0] != NULL){
    //Animated?
    if(animated){
      if(frame == 0){
        if(images[0] != NULL){
          draw_sprite(tempSprite, images[0], x - xOffset, y - yOffset);
        }
        else{
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset,makecol(0,0,0),-1,"frame");
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset + 20,makecol(0,0,0),-1,"%i NA", frame + 1);
        }
      }
      else if(frame == 1){
        if(images[1] != NULL){
          draw_sprite(tempSprite, images[1], x - xOffset, y - yOffset);
        }
        else{
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset,makecol(0,0,0),-1,"frame");
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset + 20,makecol(0,0,0),-1,"%i NA", frame + 1);
        }
      }
      else if(frame == 2){
        if(images[2] != NULL){
          draw_sprite(tempSprite, images[2], x - xOffset, y - yOffset);
        }
        else{
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset,makecol(0,0,0),-1,"frame");
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset + 20,makecol(0,0,0),-1,"%i NA", frame + 1);
        }
      }
      else if(frame == 3){
        if(images[3] != NULL){
          draw_sprite(tempSprite, images[3], x - xOffset, y - yOffset);
        }
        else{
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset,makecol(0,0,0),-1,"frame");
          textprintf_ex(tempSprite,font,x - xOffset, y - yOffset + 20,makecol(0,0,0),-1,"%i NA", frame + 1);
        }
      }
    }
    //Not animated
    else{
      draw_sprite(tempSprite, images[0], x - xOffset, y - yOffset);
    }
  }
  //Image not available? draw debug
  else{
    textprintf_ex(tempSprite,font,x - xOffset, y - yOffset,makecol(0,0,0),-1,"Image");
    textprintf_ex(tempSprite,font,x - xOffset, y - yOffset + 20,makecol(0,0,0),-1,"%i NA", type);
  }
}

tile::~tile(){

}
