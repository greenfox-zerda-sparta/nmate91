#pragma once

#include "Character.h"

class Hero : public Character {
private:
  int keycode = 2;
public:
  Hero();
  ~Hero();
  void draw_hero_direction(GameContext& context);
  void move_hero(GameContext& context, std::vector<std::vector<int>>& v);
};

