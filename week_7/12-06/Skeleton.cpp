#include "Skeleton.h"

Skeleton::Skeleton() {
  hp = 50;
  sp = 4;
  dp = 3;
}

Skeleton::~Skeleton() {
}

void Skeleton::draw_skeleton(GameContext& context, std::vector<std::vector<int>>& v) {
  for (int i = 5; i < v.size(); i++) {
    for (int j = 5; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x = j * 72;
        y = i * 72;
        v[i][j] = 2;
        goto end1;
      }
    }
  }
end1:
  context.draw_sprite("skeleton.bmp", x, y);
}