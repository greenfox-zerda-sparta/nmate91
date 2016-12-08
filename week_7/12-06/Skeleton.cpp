#include "Skeleton.h"

Skeleton::Skeleton() {
}


Skeleton::~Skeleton() {
}

void Skeleton::draw_skeleton(GameContext& context, std::vector<std::vector<int>>& v) {
  for (int i = 5; i < v.size(); i++) {
    for (int j = 5; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x = j * 72;
        y = i * 72;
        goto end1;
      }
    }
  }
end1:
  for (int i = 6; i < v.size(); i++) {
    for (int j = 6; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x = i * 72;
        y = j * 72;
        goto end2;
      }
    }
  }
end2:
  for (int i = 7; i < v.size(); i++) {
    for (int j = 7; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x = i * 72;
        y = j * 72;
        goto end3;
      }
    }
  }
end3:
  context.draw_sprite("skeleton.bmp", x, y);
}