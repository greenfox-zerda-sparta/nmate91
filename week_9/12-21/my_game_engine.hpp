#ifndef MY_GAME_ENGINE_H
#define MY_GAME_ENGINE_H

#include <SDL2/SDL.h>

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Context {
private:
  SDL_Window* screen;
public:
  Context(unsigned int width, unsigned int height);
  ~Context();
  void display_context();

};

Context::Context(unsigned int width, unsigned int height) {
  screen = SDL_CreateWindow("Gomoku", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
}

Context::~Context() {
  SDL_DestroyWindow(screen);
}

void Context::display_context() {
  if(screen == NULL) {
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
  return;
}

#endif
