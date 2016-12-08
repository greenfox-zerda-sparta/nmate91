#pragma once
#include "GameEngine.h"
#include "Map.h"

class Character{
protected:
  int x = 0;
  int y = 0;
  int hp = 0;
  int sp = 0;
  int dp = 0;
public:
  Character();
  ~Character();
  void suffer_attack(int attacker_value);
  int get_x();
  int get_y();
  int get_attack();
  void defence_move(std::vector<std::vector<int>>& v);
};

