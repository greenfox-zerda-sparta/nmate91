#include "Boss.h"

Boss::Boss() {
}


Boss::~Boss() {
}

void Boss::draw_boss(GameContext& context, std::vector<std::vector<int>>& v) {
  for (int i = 8; i < v.size(); i++) {
    for (int j = 8; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x = j * 72;
        y = i * 72;
        v[i][j] = 3;
        goto end1;
      }
    }
  }
  end1:
  context.draw_sprite("boss.bmp", x, y);
}
