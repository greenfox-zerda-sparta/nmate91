#include <iostream>
#include "my_game_engine.hpp"

using namespace std;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  Context context(640, 480);
  if(window == NULL) {
    cout << "There was error init." << endl << SDL_GetError();
  }
  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = false;
        break;
      }
    }
  }
  return 0;
}
