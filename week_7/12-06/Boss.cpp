#include "Boss.h"



Boss::Boss() {
}


Boss::~Boss() {
}

void Boss::draw_boss(GameContext& context, std::vector<std::vector<int>>& v) {
  context.draw_sprite("boss.bmp", 648, 648);
}
