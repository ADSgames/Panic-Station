#include "Intro.h"

Intro::Intro()
{
  // Load background
  if(!(intro[0] = load_bitmap( "images/intro.png", NULL))){
    abort_on_error( "Cannot find images/intro.png \n Please check your files and try again");
  }
  if(!(intro[1] = load_bitmap( "images/title.png", NULL))){
    abort_on_error( "Cannot find images/title.png \n Please check your files and try again");
  }
}

void Intro::update()
{
  // Wait 2 seconds then go to the menu
  rest(10);
  set_next_state(STATE_MENU);
}

void Intro::draw( bool toScreen)
{
  // Show background
  highcolor_fade_in( intro[0],16);
  rest( 500);
  highcolor_fade_out( 16);
  highcolor_fade_in( intro[1],16);
  rest( 500);
  highcolor_fade_out( 16);
}

Intro::~Intro()
{
  // Clear memory
  destroy_bitmap( intro[0]);
  destroy_bitmap( intro[1]);
}
