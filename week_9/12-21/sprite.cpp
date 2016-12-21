#include "sprite.hpp"

Sprite::Sprite(Uint32 color, int x, int y, int w, int h) {
  x0 = 0;
  y0 = 0;
  image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
  SDL_FillRect(image, NULL, color);
  rect = image->clip_rect;
  rect.x = x - x0;
  rect.y = y - y0;

}

void Sprite::draw(SDL_Surface* destination) {
  SDL_BlitSurface(image, NULL, destination, &rect);
  return;
}
