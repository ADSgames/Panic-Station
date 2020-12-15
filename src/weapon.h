#ifndef WEAPON_H
#define WEAPON_H

#include <allegro.h>
#include <string>

class weapon{
  public:
    weapon( int newAmmunition, int newSpeed, int newMagazineSize, int newMagazine, int reloadSpeed, int rateOfFire, int damage, std::string imagePath, std::string newName);
    virtual ~weapon();

    int getSpeed() { return speed; }
    void setSpeed(int val) { speed = val; }

    int getAmmunition() { return ammunition; }
    void setAmmunition(int val) { ammunition = val; }

    int getMagazine() { return magazine; }
    void setMagazine(int val) { magazine = val; }

    int getMagazineSize() { return magazineSize; }
    void setMagazineSize(int val) { magazineSize = val; }

    int getReloadSpeed() { return reloadSpeed; }
    void setReloadSpeed(int val) { reloadSpeed = val; }

    int getRateOfFire() { return rateOfFire; }
    void setRateOfFire(int val) { rateOfFire = val; }

    int getBulletsFired() { return bulletsFired; }
    void setBulletsFired(int val) { bulletsFired = val; }

    int getDamage() { return damage; }
    void setDamage(int val) { damage = val; }

    bool getAquired() { return aquired; }
    void setAquired(bool val) { aquired = val; }

    // Functions
    void logic();
    void addAmmo( int amount);
    void shoot();

    void draw( BITMAP *tempBuffer, int handX, int handY, bool flipped);

  protected:
  private:
    int speed;
    int ammunition;
    int magazine;
    int magazineSize;
    int reloadSpeed;
    int rateOfFire;
    int bulletsFired;
    int damage;

    bool triggerReleased;
    bool canShoot;
    bool aquired;

    int reloadTicks;

    std::string name;

    int team;

    BITMAP *image[2];
};

#endif // WEAPON_H
