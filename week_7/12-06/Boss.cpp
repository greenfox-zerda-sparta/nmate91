#include "Boss.h"

Boss::Boss(Map* map) {
  hp = 50;
  sp = 8;
  dp = 6;
  end:
  int i = rand() % 9 + 1;
  int j = rand() % 9 + 1;
  if (map->is_floor(i, j)) {
    x = i * 72;
    y = j * 72;
    map->set_map(i, j, 3);
  }
  else {
    goto end;
  }
}


Boss::~Boss() {
}

void Boss::draw_boss(GameContext& context, Map* map) {
  if (this->hp > 0) {
    context.draw_sprite("boss.bmp", x, y);
    return;
  }
  map->set_map(x / 72, y / 72, 1);
  return;
}
