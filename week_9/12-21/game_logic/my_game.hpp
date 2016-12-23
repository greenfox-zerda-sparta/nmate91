#ifndef MY_GAME_H
#define MY_GAME_H

#include "game_engine_from_eggdice.hpp"
#include "board.hpp"
#include <iostream>

class MyGame : public Game {
private:
  Board* board;
  int keycode;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};


#endif
