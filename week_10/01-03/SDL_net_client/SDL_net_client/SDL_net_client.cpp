#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "./game_logic/game_engine_from_eggdice.hpp"
#include "./game_logic/my_game.hpp"

int main(int argc, char *argv[]) {
  MyGame game;
  GameEngine engine(&game, 380, 380);
  engine.run();
  return 0;
}