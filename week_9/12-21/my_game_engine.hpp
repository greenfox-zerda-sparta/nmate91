#ifndef MY_GAME_ENGINE_H
#define MY_GAME_ENGINE_H

#define fps 30

#include <SDL2/SDL.h>
#include "sprite.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//Class context:

class Context {
private:
  SDL_Window* screen;
public:
  Context(unsigned int, unsigned int);
  ~Context();
  void display_context();
  void set_background(unsigned int, unsigned int, unsigned int);
  void load_file(string);
  void reduce_fps(Uint32&);

};

//Context definitions

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
  Uint32 starting_tick;
  set_background(255, 78, 145);
  bool running = true;
  SDL_Event event;
  while (running) {
    starting_tick = SDL_GetTicks();
    while (SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        running = false;
        break;
      }
    reduce_fps(starting_tick);
    }
  }
  return;
}

void Context::set_background(unsigned int r, unsigned int g, unsigned int b) {
  SDL_Surface *surface = SDL_GetWindowSurface(screen);
  Uint32 white = SDL_MapRGB(surface->format, r, g, b);
  Uint32 red = SDL_MapRGB(surface->format, 255, 0, 0);
  SDL_FillRect(surface, NULL, white);
  Sprite object(red, 40, 40, 40, 40);
  object.draw(surface);
  SDL_UpdateWindowSurface(screen);
  return;
}

void Context::reduce_fps(Uint32& starting_tick) {
  if ((1000 / fps) > SDL_GetTicks() - starting_tick) {
      SDL_Delay( 1000 / fps - (SDL_GetTicks() - starting_tick));
  }
  return;
}

/*void Context::load_file(string name) {
  SDL_Surface* result = SDL_LoadBMP(name.c_str());
  SDL_SetColorKey(result, SDL_TRUE, SDL_MapRGB(SDL_AllocFormat(SDL_GetWindowPixelFormat(screen)), 0xFF, 0, 0xFF));
  sprites[name] = SDL_CreateTextureFromSurface(renderer, result);
  SDL_FreeSurface(result);
}*/

#endif
