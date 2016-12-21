#include <iostream>
#include<SDL2/SDL.h>

using namespace std;

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window;
  window = SDL_CreateWindow("Subscribe!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
  if(window == NULL) {
    cout << "There was error init." << endl << SDL_GetError();
  }
  SDL_Delay(5000);
  SDL_DestroyWindow(window);
}
