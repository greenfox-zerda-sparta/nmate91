#include "Boss.h"

Boss::Boss() {
  hp = 50;
  sp = 8;
  dp = 6;
}


Boss::~Boss() {
}

void Boss::draw_boss(GameContext& context, std::vector<std::vector<int>>& v) {
  if (this->hp > 0) {
    for (int i = 7; i < v.size(); i++) {
      for (int j = 7; j < v[i].size(); j++) {
        if (v[i][j] == 1) {
          x = i * 72;
          y = j * 72;
          v[i][j] = 3;
          goto end1;
        }
      }
    }
    end1:
    context.draw_sprite("boss.bmp", x, y);
    return;
  }
  v[this->x / 72][this->y / 72] = 1;
  return;
}
