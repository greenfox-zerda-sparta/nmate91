#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>

class Sprite {
private:
  SDL_Surface* image;
  SDL_Rect rect;
  int x0, y0;
public:
  Sprite(Uint32, int, int, int, int);
  void draw(SDL_Surface*);
};


#endif
