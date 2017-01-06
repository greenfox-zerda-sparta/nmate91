#pragma once
#include "Character.h"

class Skeleton : public Character {
public:
  Skeleton(Map*);
  ~Skeleton();
  void draw_skeleton(GameContext&, Map*);
};

