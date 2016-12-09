#include "MyGame.h"

MyGame::MyGame() {
  this->map = new Map;
  this->hero = new Hero;
  this->skeleton1 = new Skeleton(map);
  this->skeleton2 = new Skeleton(map);
  this->skeleton3 = new Skeleton(map);
  this->boss = new Boss(map);
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
  boss->draw_boss(context, map);
  skeleton1->draw_skeleton(context, map);
  skeleton2->draw_skeleton(context, map);
  skeleton3->draw_skeleton(context, map);
  hero->draw_hero_direction(context);
  hero->move_hero(context, v);
  fight(context);
  context.render();
}

void MyGame::fight(GameContext& context) {
  if ((hero->get_x() == skeleton1->get_x()) && (hero->get_y() == skeleton1->get_y()) && context.was_key_pressed(SPACE))
  {
    skeleton1->suffer_attack(hero->get_attack());
    skeleton1->defence_move(map);
    context.render();
  }
  if ((hero->get_x() == skeleton2->get_x()) && (hero->get_y() == skeleton2->get_y()) && context.was_key_pressed(SPACE)) {
    skeleton2->suffer_attack(hero->get_attack());
    skeleton2->defence_move(map);
    context.render();
  }
  if ((hero->get_x() == skeleton3->get_x()) && (hero->get_y() == skeleton3->get_y()) && context.was_key_pressed(SPACE)) {
    skeleton3->suffer_attack(hero->get_attack());
    skeleton3->defence_move(map);
    context.render();
  }
  if ((hero->get_x() == boss->get_x()) && (hero->get_y() == boss->get_y()) && context.was_key_pressed(SPACE)) {
    boss->suffer_attack(hero->get_attack());
    boss->defence_move(map);
    context.render();
  }
  return;
}