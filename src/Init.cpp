#include "Init.h"

Init::Init() {
  // Set window title
  set_window_title("Error");

  // Set screen mode
  if (false == true) {
    resDiv = 1;
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1280, 960, 0, 0) != 0) {
      resDiv = 2;
      if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 640, 480, 0, 0) != 0) {
        resDiv = 4;
        if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 320, 240, 0, 0) != 0) {
          set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
          allegro_message("Unable to go into fullscreen graphic mode\n%s\n",
                          allegro_error);
          exit(1);
        }
      }
    }
  } else {
    resDiv = 1;
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 960, 0, 0) != 0) {
      resDiv = 2;
      if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
        resDiv = 4;
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 320, 240, 0, 0) != 0) {
          set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
          allegro_message("Unable to set any windowed graphic mode\n%s\n",
                          allegro_error);
          exit(1);
        }
      }
    }
  }

  // Fonts
  FONT *f1, *f2, *f3, *f4, *f5;

  // Loading "pixelart" font

  if (!(f1 = load_font("fonts/pixelart.pcx", NULL, NULL))) {
    abort_on_error(
        "Cannot find fonts/pixelart.pcx \n Please check your files and try "
        "again");
  }
  f2 = extract_font_range(f1, ' ', 'A' - 1);
  f3 = extract_font_range(f1, 'A', 'Z');
  f4 = extract_font_range(f1, 'Z' + 1, 'z');

  // Merge temporary fonts to create "pixelart"
  pixelart = merge_fonts(f4, f5 = merge_fonts(f2, f3));

  // Loading "pixelart_2" font

  if (!(f1 = load_font("fonts/pixelart_2.pcx", NULL, NULL))) {
    abort_on_error(
        "Cannot find fonts/pixelart_2.pcx \n Please check your files and try "
        "again");
  }
  f2 = extract_font_range(f1, ' ', 'A' - 1);
  f3 = extract_font_range(f1, 'A', 'Z');
  f4 = extract_font_range(f1, 'Z' + 1, 'z');

  // Merge temporary fonts to create "pixelart_2"
  pixelart_2 = merge_fonts(f4, f5 = merge_fonts(f2, f3));

  // Loading "munro_large" font

  if (!(f1 = load_font("fonts/munro_large.pcx", NULL, NULL))) {
    abort_on_error(
        "Cannot find fonts/munro_large.pcx \n Please check your files and try "
        "again");
  }
  f2 = extract_font_range(f1, ' ', 'A' - 1);
  f3 = extract_font_range(f1, 'A', 'Z');
  f4 = extract_font_range(f1, 'Z' + 1, 'z');

  // Merge temporary fonts to create "munro_large" font
  munro_large = merge_fonts(f4, f5 = merge_fonts(f2, f3));

  // Destroy temporary fonts
  destroy_font(f1);
  destroy_font(f2);
  destroy_font(f3);
  destroy_font(f4);
  destroy_font(f5);

  // Creates a random number generator (based on time)
  srand(time(NULL));

  // Sets the Windows window text
  set_window_title("Panic Station");
}

void Init::update() {
  // Change to splash screen
  set_next_state(STATE_GAME);
}

void Init::draw(bool toScreen) {}

Init::~Init() {}
