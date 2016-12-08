#pragma once
#include "GameEngine.h"

class Character {
protected:
  int x = 0;
  int y = 0;
public:
  Character();
  virtual ~Character();
  virtual void set_x(int);
  virtual void set_y(int);
};

