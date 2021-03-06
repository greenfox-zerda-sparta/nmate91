#include "GameEngine.h"
#include "MyGame.h"
#include "Map.h"
#include "vld.h"

int main(int argc, char* args[]) {
  srand(time(NULL));
  MyGame game;
  GameEngine engine(&game, 720, 720);
  engine.run();
  return 0;
}