#pragma once

#include "GameEngine.h"
#include "Map.h"
#include "Character.h"

class MyGame : public Game, public Map, public Character {
private:
  int x_player = 0;
  int y_player = 0;
  int x_skeleton1 = 0;
  int y_skeleton1 = 0;
  int x_skeleton2 = 0;
  int y_skeleton2 = 0;
  int x_skeleton3 = 0;
  int y_skeleton3 = 0;
  int x_boss = 648;
  int y_boss = 648;
  int keycode = 2;
  int ghost_counter = 0;
public:
  MyGame();
  ~MyGame();
  virtual void draw_map(GameContext& context);
  virtual void draw_player_direction(GameContext& context, int keycode);
  virtual void init(GameContext& context);
  virtual void render(GameContext& context);
  virtual void draw_skeleton(GameContext& context);
};
