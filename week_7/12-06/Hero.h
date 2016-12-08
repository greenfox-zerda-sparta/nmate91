#pragma once

#include "Character.h"

class Hero : public Character {
public:
  Hero();
  ~Hero();
  void draw_hero_direction(GameContext& context, int keycode);
  void move_hero(GameContext& context, int keycode, std::vector<std::vector<int>>&);
};

