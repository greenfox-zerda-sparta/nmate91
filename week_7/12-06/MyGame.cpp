#include "MyGame.h"


MyGame::MyGame() {
  this->map = new Map;
  this->v = map->get_vector();
}

MyGame::~MyGame() {
  delete map;
}

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-left.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("skeleton.bmp");
  context.load_file("boss.bmp");
}

void MyGame::draw_player_direction(GameContext& context, int keycode) {
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

void MyGame::draw_skeleton(GameContext& context) {
  for (int i = 5; i < v.size(); i++) {
    for (int j = 5; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton1 = j * 72;
        y_skeleton1 = i * 72;
        goto end1;
      }
    }
  }
  end1:
  for (int i = 6; i < v.size(); i++) {
    for (int j = 6; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton2 = i * 72;
        y_skeleton2 = j * 72;
        goto end2;
      }
    }
  }
  end2:
  for (int i = 7; i < v.size(); i++) {
    for (int j = 7; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton3 = i * 72;
        y_skeleton3 = j * 72;
        goto end3;
      }
    }
  }
  end3:
  context.draw_sprite("skeleton.bmp", x_skeleton1, y_skeleton1);
  context.draw_sprite("skeleton.bmp", x_skeleton2, y_skeleton2);
  context.draw_sprite("skeleton.bmp", x_skeleton3, y_skeleton3);
  context.draw_sprite("boss.bmp", x_boss, y_boss);
}

void MyGame::draw_map(GameContext& context) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 0) {
        context.draw_sprite("wall.bmp", i * 72, j * 72);
      }
      else if (v[i][j] == 1) {
        context.draw_sprite("floor.bmp", i * 72, j * 72);
      }
    }
  }
}

void MyGame::render(GameContext& context) {
  draw_map(context);
  draw_skeleton(context);
  draw_player_direction(context, keycode);
  if (context.was_key_pressed(ARROW_DOWN)) {
    set_y(y + 72);
    if (y > (720 - 72)) {
      set_y(720 - 72);
    }
    else if (v[x / 72][y / 72] == 0) {
      set_y(y - 72);
    }
    keycode = 2;
  }
  else if (context.was_key_pressed(ARROW_UP)) {
    set_y(y - 72);
    if (y < 0) {
      set_y(0);
    }
    else if (v[x / 72][y / 72] == 0) {
      set_y(y + 72);
    }
    keycode = 0;
  }
  else if (context.was_key_pressed(ARROW_LEFT)) {
    set_x(x - 72);
    if (x < 0) {
      set_x(0);
    }
    else if (v[x / 72][y / 72] == 0) {
      set_x(x + 72);
    }
    keycode = 3;
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) {
    set_x(x + 72);
    if (x >(720 - 72)) {
      set_x(720 - 72);
    }
    else if (v[x / 72][y / 72] == 0) {
      set_x(x - 72);
    }
    keycode = 1;
  }
  context.render();
}