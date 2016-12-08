#pragma once

#include "GameEngine.h"
#include <time.h>


class Map {
private:
  std::vector<std::vector<int>> v; 
public:
  Map();
  ~Map();
  std::vector<std::vector<int>> get_vector();
  void draw_map(GameContext& context);
};

