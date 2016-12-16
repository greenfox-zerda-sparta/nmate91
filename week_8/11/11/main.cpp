#include <iostream>
#include "draw.h"
#include <SDL.h>

void draw_triangle(draw& d, SDL_Renderer* renderer, int line_lenght) {
  if (line_lenght > 1) {
    for (int i = 0; i < 3; i++) {
      d.DrawBy(renderer, line_lenght);
      d.TurnTo(120);
      draw_triangle(d, renderer, line_lenght / 2);
    }
    draw_triangle(d, renderer, line_lenght / 2);
  }
  return;
}

int main(int argc, char ** argv) {
  bool quit = false;
  SDL_Event event;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* window = SDL_CreateWindow("SDL2 Fractal",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 512, 512, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawColor(renderer, 89, 162, 122, 0);
  SDL_RenderClear(renderer);
  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    draw d;
    draw_triangle(d, renderer, 512);
  }
  SDL_RenderPresent(renderer);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}