#pragma once
#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

class Fight {
private:
  int counter = 0;
  Monster mo;
  Player po;
public:
  Fight();
  ~Fight();
  void fight();
  void monster_attack();
  void player_attack();
};

