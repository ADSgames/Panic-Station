#include "weapon.h"

weapon::weapon( int newAmmunition, int newSpeed, int newMagazineSize, int newMagazine, int newReloadSpeed, int newRateOfFire, int newDamage, std::string imagePath, std::string newName){
  ammunition = newAmmunition;
  speed = newSpeed;
  magazineSize = newMagazineSize;
  magazine = newMagazine;
  reloadSpeed = newReloadSpeed;
  rateOfFire = newRateOfFire;
  damage = newDamage;
  name = newName;

  triggerReleased = true;
  canShoot = true;

  image[0] = load_bitmap(imagePath.c_str(), NULL);
}

weapon::~weapon(){
  //dtor
}

// Shoot weapon
void weapon::shoot(){
  if(rateOfFire == -1 && !triggerReleased)
    canShoot = false;
  else
    canShoot = true;

  triggerReleased=false;
}

// Logic of gun (reloading ect)
void weapon::logic(){
  // Reload time if empty
  if( magazine == 0)
    reloadTicks++;

  // Reloaded
  if( reloadTicks >= reloadSpeed){
    reloadTicks=0;
    if( ammunition >= magazineSize){
      ammunition -= magazineSize;
      magazine = magazineSize;
    }
    else{
      magazine = ammunition;
      ammunition = 0;
    }
  }
}

// Give some ammo
void weapon::addAmmo( int amount){
  ammunition += amount;
}

// Draw gun to screen
void weapon::draw( BITMAP *tempBuffer, int handX, int handY, bool flipped){
  if( !flipped)
    draw_sprite( tempBuffer, image[0], handX - image[0] -> w, handY);
  else
     draw_sprite_h_flip( tempBuffer, image[0], handX, handY);
}
