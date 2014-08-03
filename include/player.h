#ifndef PLAYER_H
#define PLAYER_H

#include <allegro.h>
#include <alpng.h>

#include "globals.h"
#include "tools.h"
#include "projectile.h"

#include "tileMap.h"

#define ANIMATION_SPEED 5
#define JUMPING_HEIGHT 192

class player{
  public:
    player();
    ~player();

    char path[480];

    struct weapons{
        int speed;
        int ammunition;
        int magazine;
        int magazineSize;
        int reloadSpeed;
        int rateOfFire;
        int bulletsFired;
        int damage;
        bool aquired;
    }weapon[10];

    int currentWeapon;

    void load_images();
    void load_sounds();

    int getX();
    int getY();

    int getAmmo1();

    bool getDead();

    void setFinishLevel(int newFinishLevel);
    bool getFinishLevel();

    vector<projectile>* getBullets();

    void setDead(bool newDead);
    void spawncommand(tileMap *newMap);

    void update(tileMap *newMap);
    void draw(BITMAP* temp, int tile_map_x, int tile_map_y);

  private:
    int x;
    int y;

    bool triggerReleased;
    bool canShoot;

    int reloadTicks;


    int weaponScrollLoop;

    int fallheight;

    int stamina;
    int staminaLoop;

    int health;
    int oxygen;
    int oxygenHarm;

    bool staminaBoost;
    bool finishLevel;

    int level;

    int deathcount;

    bool isTalkingToNpc;
    int npc_ID;

    bool isReadingBlock;
    int read_ID;

    bool moving_to_cover;

    int switch_loop;
    int switch_frame;
    int switch_direction;

    bool elevator_called;
    int elevator_loop;
    int elevator_frame;
    int elevator_direction;

    bool initial_spawn;

    int material;

    int height;
    bool canFall;
    bool jumping;
    bool jumping_animation_done;
    bool dead;
    bool shooting;
    bool blindfiring;
    bool isSprinting;
    bool isCrouching;
    bool inLiquid;
    bool headInLiquid;

    int shooting_animation_sequence;
    int walking_animation_sequence;
    int jumping_animation_sequence;
    int jump_height;
    int characterDir;
    int yVelocity;

    vector<projectile> bullets;

    // 0-3 left, 4-7 right, 8-11 up 12-17 jump left 18-23 jump right <-- This isn't accurate
    BITMAP* player_images[36];

    BITMAP* statusbar;
    BITMAP* gui_paper;
    BITMAP* gui_statue;
    BITMAP* gui_pistol;
    BITMAP* gui_mp5;
    BITMAP* gui_ppsh;
    BITMAP* gui_minigun;
    BITMAP* gui_remington;


    //Sounds
    SAMPLE* walk1;
    SAMPLE* walk2;
    SAMPLE* jump;
    SAMPLE* death_fall;
    SAMPLE* death_impact;
    SAMPLE* getItem;
    SAMPLE* getBonus;
    SAMPLE* dryfire;
    SAMPLE* Switch;
    SAMPLE* walk_stone;
    SAMPLE* glass;
    SAMPLE* alarm;
    SAMPLE* elevator;
    SAMPLE* wood_smash;
    SAMPLE* pistol_boxget;
    SAMPLE* hurt_fall;
    SAMPLE* death_radioactive;
    SAMPLE* item_energydrink;
    SAMPLE* squeak_mailbox;
    SAMPLE* squeak_door;
    SAMPLE* water_splash;
    SAMPLE* water_walk;
    SAMPLE* weapon_pickup;
    SAMPLE* ammunition_pickup;

    //Esc key handler variables
    bool exit_menu_open;
};

#endif
