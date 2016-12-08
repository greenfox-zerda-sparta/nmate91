#include "Hero.h"

Hero::Hero() {
}

Hero::~Hero() {
}

void Hero::draw_hero_direction(GameContext& context, int keycode) {
  switch (keycode) {
  case 0:
    context.draw_sprite("hero-up.bmp", x, y);
    break;
  case 1:
    context.draw_sprite("hero-right.bmp", x, y);
    break;
  case 2:
    context.draw_sprite("hero-down.bmp", x, y);
    break;
  case 3:
    context.draw_sprite("hero-left.bmp", x, y);
    break;
  }
}

void Hero::move_hero(GameContext& context, int keycode, std::vector<std::vector<int>>& v) {
  if (context.was_key_pressed(ARROW_DOWN)) {
    y = y + 72;
    if (y > (720 - 72)) {
      y = (720 - 72);
    }
    else if (v[x / 72][y / 72] == 0) {
      y = y - 72;
    }
    keycode = 2;
  }
  else if (context.was_key_pressed(ARROW_UP)) {
    y = y - 72;
    if (y < 0) {
      y = 0;
    }
    else if (v[x / 72][y / 72] == 0) {
      y = y + 72;
    }
    keycode = 0;
  }
  else if (context.was_key_pressed(ARROW_LEFT)) {
    x = x - 72;
    if (x < 0) {
      x = 0;
    }
    else if (v[x / 72][y / 72] == 0) {
      x = x + 72;
    }
    keycode = 3;
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) {
    x = x + 72;
    if (x >(720 - 72)) {
      x = (720 - 72);
    }
    else if (v[x / 72][y / 72] == 0) {
      x = x - 72;
    }
    keycode = 1;
  }
}