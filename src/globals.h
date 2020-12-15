#ifndef GLOBALS_H
#define GLOBALS_H

//All libaries
#include <allegro.h>

//All defined presets put here
//tile Attributes
#define gas 0
#define solid 1
#define liquid 2
#define climb 3
#define harmful 4
#define interactive 5
#define item 6
#define spawn 7
#define cover 8
#define npc 9
#define levelend 10
#define readable 11

//Game screens
#define INGAME 1
#define SAVE 5
#define OPEN 6

//Character directions
// 0-3 left, 4-7 right, 8-11 up
#define LEFT 0
#define RIGHT 4
#define UP 8

//Tiles (0-198)
#define tile_air 0
#define tile_medpack 1
#define tile_sky_1 2
#define tile_grass_1 3
#define tile_tallgrass_1 4
#define tile_mailbox_1 5
#define tile_mailbox_2 6

#define tile_cloud_1 7
#define tile_asphalt_grass 8
#define tile_brick_yellow 9
#define tile_brick_green 10
#define tile_green_light 11
#define tile_temperature_1 12
#define tile_id 13
#define tile_old_vorticon 14
#define tile_asdf 15

#define tile_cement_1 16
#define tile_cement_2 17
#define tile_cement_3 18
#define tile_cement_4 19
#define tile_cement_5 20
#define tile_cement_6 21
#define tile_cement_7 22
#define tile_cement_8 23
#define tile_cement_9 24

#define tile_generator_off 25
#define tile_generator_on 43
#define tile_generator_1 44
#define tile_generator_2 45

#define tile_pipe_1 26
#define tile_pipe_2 27
#define tile_pipe_3 28
#define tile_pipe_4 29
#define tile_pipe_5 30
#define tile_pipe_6 31
#define tile_pipe_7 32
#define tile_pipe_8 33
#define tile_pipe_9 34
#define tile_pipe_10 35
#define tile_pipe_11 36
#define tile_pipe_12 37
#define tile_pipe_13 38
#define tile_pipe_14 39
#define tile_pipe_15 40

#define tile_energydrink 41
#define tile_ammo_pistol 42

#define tile_light_cage_1 46
#define tile_light_cage_2 47
#define tile_light_cage_3 48
#define tile_light_cage_4 49

#define tile_elevator_control 60

#define tile_elevator_1 50
#define tile_elevator_2 51
#define tile_elevator_3 52
#define tile_elevator_4 53
#define tile_elevator_5 54
#define tile_elevator_6 55
#define tile_elevator_7 56
#define tile_elevator_8 57
#define tile_elevator_9 58
#define tile_elevator_10 59
#define tile_elevator_11 60
#define tile_elevator_12 61
#define tile_elevator_13 62
#define tile_elevator_14 63
#define tile_elevator_15 64
#define tile_elevator_16 65
#define tile_elevator_17 66
#define tile_elevator_18 67
#define tile_elevator_19 68
#define tile_elevator_20 69
#define tile_elevator_21 70
#define tile_elevator_22 71
#define tile_elevator_23 72
#define tile_elevator_24 73
#define tile_elevator_25 74
#define tile_elevator_26 75
#define tile_elevator_27 76
#define tile_elevator_28 77
#define tile_elevator_29 78
#define tile_elevator_30 79
#define tile_elevator_31 80
#define tile_elevator_32 81
#define tile_elevator_33 82

#define tile_elevator_shroud_1 91
#define tile_elevator_shroud_2 92
#define tile_elevator_shroud_3 93
#define tile_elevator_shroud_4 94
#define tile_elevator_shroud_5 95
#define tile_elevator_shroud_6 96

#define tile_crate1_1 83
#define tile_crate1_2 84
#define tile_crate1_3 85
#define tile_crate1_4 86
#define tile_crate1_5 87

#define tile_cement_radioactive_1 97
#define tile_cement_radioactive_2 98
#define tile_cement_radioactive_3 99
#define tile_cement_radioactive_4 100

#define tile_pistol_magazine 88
#define tile_pistol_box 89
#define tile_cover_1 90
#define tile_grass_3 101

#define tile_roof_1 102
#define tile_roof_2 103
#define tile_roof_3 104
#define tile_roof_4 105

#define tile_brick_1 106
#define tile_brick_door_1 107
#define tile_brick_door_2 108
#define tile_brick_2 109
#define tile_brick_window_1 110
#define tile_fence 111
#define tile_roof_5 112
#define tile_roof_6 113
#define tile_wallpaper_1 114
#define tile_roof_chimney 115
#define tile_roof_chimney_1 116

#define tile_brown_door_1 117
#define tile_brown_door_2 118
#define tile_door_1 119
#define tile_door_2 120

#define tile_cement_wood 121

#define tile_water 122
#define tile_water_cement_left_1 123
#define tile_water_cement_left_2 124
#define tile_water_cement_left_3 125
#define tile_water_cement_right_1 126
#define tile_water_cement_right_2 127
#define tile_water_cement_right_3 128
#define tile_water_cement_middle 129

#define tile_dirt 130
#define tile_grass_dirt 131

#define tile_pistol 132
#define tile_mp5 133
#define tile_ppsh 134
#define tile_minigun 135
#define tile_remington 136

#define tile_ammo_mp5 137
#define tile_ammo_remington 138
#define tile_ammo_ppsh 139
#define tile_ammo_minigun 140




//Where backround images were(Removed for number allocation)

//NPC's (300-400)
#define tile_npc_allan 300
#define tile_npc_gerald 301

//Readable (400-500)
#define tile_readable_paper 400
#define tile_readable_statue 401

//Spawners (199+)
#define tile_spawn_player 199
#define tile_spawn_vorticon 200
#define tile_spawn_robot 201
#define tile_spawn_mutant 202

//Level end block
#define tile_teleporter 299

//Enemies
#define enemy_sentry 1
#define enemy_mutant 2

extern FONT* pixelart;
extern FONT* pixelart_2;
extern FONT* munro_large;

extern BITMAP* tileSprites[500][4];
extern BITMAP* projectileSprites[10][3];

// Set next state
void set_next_state( int newState );

//Game states
enum GameStates
{
    STATE_NULL,
    STATE_INIT,
    STATE_INTRO,
    STATE_MENU,
    STATE_EDIT,
    STATE_GAME,
    STATE_EXIT,
};

// Frames
extern int frames_done;
extern volatile int game_time;
extern volatile int ticks;
extern bool updatesEnabled;


// Resdiv
extern int resDiv;

//State variables
extern int stateID;
extern int nextState;

#endif
