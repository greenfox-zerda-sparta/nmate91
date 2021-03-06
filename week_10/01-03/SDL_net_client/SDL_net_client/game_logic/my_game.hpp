#pragma once

#include "game_engine_from_eggdice.hpp"
#include "board.hpp"

class MyGame : public Game {
private:
  Board* board;
  int keycode;
  int player_1_counter;
  int player_2_counter;
  TCPsocket client;
  SDLNet_SocketSet set;
  int array_to_send_coordinates[100];
  int array_to_allocate_coordinates[2];
  const int* client_coordinates;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext&);
  virtual void render(GameContext&);
  void draw_board(GameContext&);
};
