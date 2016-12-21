#ifndef MY_GAME_ENGINE_H
#define MY_GAME_ENGINE_H

#include <SDL2/SDL.h>

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class Context {
private:
  SDL_WINDOW* screen;
public:
  Context(unsigned int width, unsigned int height);
  ~Context();


};

Context::Context(unsigned int width, unsigned int height) {
  screen = SDL_CreateWindow("Bomoku", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
}

Context::~Context() {
  SDL_DestroyWindow(screen);
}

#endif
