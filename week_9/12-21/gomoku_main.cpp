#include <iostream>
#include "my_game_engine.hpp"

using namespace std;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  Context context(640, 480);
  context.display_context();
  return 0;
}
