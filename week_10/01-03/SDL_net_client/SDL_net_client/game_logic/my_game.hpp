#pragma once

#include "game_engine_from_eggdice.hpp"
#include "board.hpp"
#include <iostream>

class MyGame : public Game {
private:
  Board* board;
  int keycode;
  int player_1_counter;
  int player_2_counter;
  TCPsocket client;
  char text[100];
  const char* client_text;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext&);
  virtual void render(GameContext&);
  void draw_board(GameContext&);
};
