#include "MyGame.h"
#include <time.h>

MyGame::MyGame() {
  srand(time(NULL));
  std::vector<std::vector<int>> vic(10, std::vector<int>(10, 1));
  this->v = vic;
  int random_number = 0;
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[i].size() - 1; j++) {
      random_number = rand() % 2;
      v[i][j] = random_number;
    }
  }
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[i].size() - 1; j++) {
      if (v[i - 1][j - 1] == 0) {
        v[i][j] = 1;
      }
      else if (v[i][j - 1] == 1 && v[i - 1][j] == 1 && v[i][j + 1] == 1) {
        v[i][j] = 0;
      }
      else if (v[i][j - 1] == 0 && v[i + 1][j] == 0 && v[i - 1][j] == 0 && v[i][j + 1] == 0) {
        v[i][j] = 0;
      }
      else if ((v[i][j - 1] == 1 && v[i + 1][j] == 1) || (v[i - 1][j] == 1 && v[i][j + 1] == 1)) {
        v[i][j] = 1;
      }
    }
  }
  for (int i = 5; i < v.size(); i++) {
    for (int j = 5; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        v[i][j] = 2;
        ghost_counter++;
        break;
      }
    }
    if (ghost_counter == 3) {
      break;
    }
  }
}

MyGame::~MyGame() {
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

void MyGame::draw_char_direction(GameContext& context, int keycode) {
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

void MyGame::draw_map(GameContext& context) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 0) {
        context.draw_sprite("wall.bmp", i * 72, j * 72);
      }
      else if (v[i][j] == 1) {
        context.draw_sprite("floor.bmp", i * 72, j * 72);
      }
      else if (v[i][j] == 2) {
        context.draw_sprite("skeleton.bmp", i * 72, j * 72);
      }
    }
  }
  context.draw_sprite("boss.bmp", (v.size() - 1) * 72, (v.size() - 1) * 72);
}

void MyGame::render(GameContext& context) {
  draw_map(context);
  draw_char_direction(context, keycode);
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
    if (x > (720 - 72)) {
      x = (720 - 72);
    }
    else if (v[x / 72][y / 72] == 0) {
      x = x - 72;
    }
    keycode = 1;
  }
  context.render();
}