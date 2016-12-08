#pragma once
#include "Character.h"


class Skeleton : public Character {
public:
  Skeleton();
  ~Skeleton();
  void draw_skeleton(GameContext&, std::vector<std::vector<int>>& v);
};

