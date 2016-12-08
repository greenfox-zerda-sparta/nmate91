#pragma once

#include "Character.h"

class Boss : public Character {
public:
  Boss();
  ~Boss();
  void draw_boss(GameContext& context, std::vector<std::vector<int>>& v);
};

