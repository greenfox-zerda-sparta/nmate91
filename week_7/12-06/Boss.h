#pragma once

#include "Character.h"

class Boss : public Character {
public:
  Boss(Map*);
  ~Boss();
  void draw_boss(GameContext& context, Map*);
};

