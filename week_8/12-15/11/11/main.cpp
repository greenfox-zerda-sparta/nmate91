#include <iostream>
#include "draw.h"
#include <SDL.h>

void draw_something(draw& d, SDL_Renderer* renderer, int x, int y) {
  if (x < 600 && y < 600 && x < y) {
    d.DrawTo(renderer, x + 200, y);
    return draw_something(d, renderer, x + 200, y);
  } 
  else if (x < 600 && y < 600 && x == y) {
    d.DrawTo(renderer, x, y + 200);
    return draw_something(d, renderer, x, y + 200);
  }
  return;
}

int main(int argc, char ** argv) {
  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    draw d;
    draw_something(d, renderer, 0, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}