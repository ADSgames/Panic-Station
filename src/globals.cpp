#include "globals.h"

BITMAP* tileSprites[500][4];
BITMAP* projectileSprites[10][3];

FONT* pixelart;
FONT* pixelart_2;
FONT* munro_large;

// Frames
int frames_done;
volatile int game_time = 0;
volatile int ticks = 0;
bool updatesEnabled = true;

// Resdiv
int resDiv;

// State variables
int stateID;
int nextState;
