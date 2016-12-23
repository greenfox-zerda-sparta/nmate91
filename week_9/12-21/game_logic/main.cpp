#include <iostream>

#ifndef TEST

#include "game_engine_from_eggdice.hpp"
#include "my_game.hpp"


int main (int argc, char** argv) {
  MyGame game;
  GameEngine engine(&game, 380, 380);
  engine.run();
  return 0;
}

#endif
