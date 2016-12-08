#pragma once

#include "GameEngine.h"
#include "Map.h"
#include "Hero.h"
#include "Skeleton.h"
#include "Boss.h"

class MyGame : public Game {
private:
  Map* map;
  Hero* hero;
  Skeleton* skeleton;
  Boss* boss;
  std::vector<std::vector<int>> v;
  int keycode = 2;
public:
  MyGame();
  ~MyGame();
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
};
