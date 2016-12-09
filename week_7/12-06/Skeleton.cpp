#include "Skeleton.h"

Skeleton::Skeleton(Map* map) {
  hp = 50;
  sp = 4;
  dp = 3;
  int map_value = 2;
  end:
  int i = rand() % 9 + 1;
  int j = rand() % 9 + 1;
  if (map->is_floor(i, j)) {
    x = i * 72;
    y = j * 72;
    map->set_map(i, j, map_value);
  }
  else {
    goto end;
  }
}

Skeleton::~Skeleton() {
}

void Skeleton::draw_skeleton(GameContext& context, Map* map) {
  if (this->hp > 0) {
    context.draw_sprite("skeleton.bmp", x, y);
    return;
  }
  map->set_map(x/72, y/72, 1);
  return;
}
