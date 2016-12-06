#include "GameEngine.h"
#include "MyGame.h"

int main(int argc, char* args[]) {
  MyGame game;
  GameEngine engine(&game, 720, 720);
  engine.run();
  return 0;
}