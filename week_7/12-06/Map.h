#pragma once

#include "GameEngine.h"


class Map {
private:
  std::vector<std::vector<int>> v; 
public:
  Map();
  ~Map();
  std::vector<std::vector<int>> get_vector();
  void draw_map(GameContext& context);
  bool is_floor(int, int);
  bool is_monster(int, int);
  bool is_monster_or_floor(int, int);
  void set_map(int, int, int);
};

