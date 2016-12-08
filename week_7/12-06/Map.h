#pragma once

#include "GameEngine.h"

class Map {
private:
  std::vector<std::vector<int>> v; 
public:
  Map();
  ~Map();
  std::vector<std::vector<int>> get_vector();
};

