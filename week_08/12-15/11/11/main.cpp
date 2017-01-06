#include <iostream>
#include "draw.h"
#include <SDL.h>

void draw_something(draw& d, SDL_Renderer* renderer, int x_i, int y_i, int x, int y) {
  if (x_i >= 2 && y_i >= 2) {
    d.MoveTo(x + x_i / 3, y);
    d.DrawTo(renderer, x + x_i / 3, y + y_i);
    draw_something(d, renderer, x_i / 3, y_i / 3, x + x_i / 3, y);

    d.MoveTo(x + 2 * x_i / 3, y);
    d.DrawTo(renderer, x + 2 * x_i / 3, y + y_i);
    draw_something(d, renderer, x_i / 3, y_i / 3, x + x_i / 3, y + 2 * y_i / 3);

    d.MoveTo(x, y + y_i / 3);
    d.DrawTo(renderer, x + x_i, y + y_i / 3);    
    draw_something(d, renderer, x_i / 3, y_i / 3, x + 2 * x_i / 3, y + y_i / 3);

    d.MoveTo(x, y + 2 * y_i / 3);
    d.DrawTo(renderer, x + x_i, y + 2 * y_i / 3);
    draw_something(d, renderer, x_i / 3, y_i / 3, x, y + y_i / 3);
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
  SDL_SetRenderDrawColor(renderer, 255, 20, 147, 0);
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

    draw d;
    draw_something(d, renderer, 600, 600, 0, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}