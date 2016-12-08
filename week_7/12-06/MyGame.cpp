#include "MyGame.h"


MyGame::MyGame() {
  this->map = new Map;
  this->hero = new Hero;
  this->skeleton1 = new Skeleton;
  this->skeleton2 = new Skeleton;
  this->skeleton3 = new Skeleton;
  this->boss = new Boss;
  this->v = map->get_vector();
}

MyGame::~MyGame() {
  delete map;
  delete hero;
  delete skeleton1;
  delete skeleton2;
  delete skeleton3;
  delete boss;
}

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-left.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("skeleton.bmp");
  context.load_file("boss.bmp");
}

void MyGame::render(GameContext& context) {
  map->draw_map(context);
  skeleton1->draw_skeleton(context, v);
  skeleton2->draw_skeleton(context, v);
  skeleton3->draw_skeleton(context, v);
  boss->draw_boss(context, v);
  hero->draw_hero_direction(context, keycode);
  hero->move_hero(context, keycode, v);
  context.render();
}