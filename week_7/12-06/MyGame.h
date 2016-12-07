#pragma once

#include "GameEngine.h"

class MyGame : public Game {
private:
  std::vector<std::vector<int>> v;
  int x = 0;
  int y = 0;
  int keycode = 2;
public:
  MyGame();
  ~MyGame();
  virtual void draw_char_direction(GameContext& context, int keycode);
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};

