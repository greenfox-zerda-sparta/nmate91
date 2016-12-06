#pragma once
#include "GameEngine.h"

class MyGame : public Game {
private:
  std::vector<std::vector<int>> v;
  int x = 0;
  int y = 0;
  int keycode;
public:
  MyGame() {
    std::vector<std::vector<int>> vic(10, std::vector<int>(10, 100));
    this->v = vic;
    int random_number = 0;
    for (int j = 0; j < v.size(); j++) {
      for (int i = 0; i < v[j].size(); i++) {
        random_number = rand() % 100 + 1;
        v[j][i] = random_number;
      }
    }
  }
  ~MyGame() {
  }

  virtual void init(GameContext& context) {
    context.load_file("floor.bmp");
    context.load_file("wall.bmp");
    context.load_file("hero-down.bmp");
    context.load_file("hero-up.bmp");
    context.load_file("hero-left.bmp");
    context.load_file("hero-right.bmp");
  }

  virtual void render(GameContext& context) {
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] % 5 == 0) {
          context.draw_sprite("wall.bmp", i * 72, j * 72);
        }
        else {
          context.draw_sprite("floor.bmp", i * 72, j * 72);
        }
      }
    }
    context.draw_sprite("hero-down.bmp", x, y);
    if (context.was_key_pressed(ARROW_DOWN)) {
      y = y + 72;
      if (y > (720 - 72)) {
        y = (720 - 72);
        context.render();
      }
      else if (v[x / 72][y / 72] % 5 == 0) {
        y = y - 72;
      }
      context.reset_keys();
      context.on_key_down(ARROW_DOWN);
      context.draw_sprite("hero-down.bmp", x, y);
    }
    else if (context.was_key_pressed(ARROW_UP)) {
      y = y - 72;
      if (y < 0) {
        y = 0;
        context.render();
      }
      else if (v[x / 72][y / 72] % 5 == 0) {
        y = y + 72;
      }
      context.reset_keys();
      context.on_key_down(ARROW_UP);
      context.draw_sprite("hero-up.bmp", x, y);
    }
    else if (context.was_key_pressed(ARROW_LEFT)) {
      x = x - 72;
      if (x < 0) {
        x = 0;
        context.render();
      }
      else if (v[x / 72][y / 72] % 5 == 0) {
        x = x + 72;
      }
      context.reset_keys();
      context.on_key_down(ARROW_LEFT);
      context.draw_sprite("hero-left.bmp", x, y);
    }
    else if (context.was_key_pressed(ARROW_RIGHT)) {
      x = x + 72;
      if (x > (720 - 72)) {
        x = (720 - 72);
        context.render();
      }
      else if (v[x / 72][y / 72] % 5 == 0) {
        x = x - 72;
      }
      context.reset_keys();
      context.on_key_down(ARROW_RIGHT);
      context.draw_sprite("hero-right.bmp", x, y);
    }
    context.render();
  }
};

