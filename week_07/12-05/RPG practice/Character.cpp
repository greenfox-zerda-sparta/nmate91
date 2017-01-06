#include "stdafx.h"
#include "Character.h"


Character::Character() {
}


Character::~Character() {
}

int Character::attack() {
  return attack_value;
}

int Character::defence() {
  return def_value;
}

int Character::get_hp() {
  return hp_value;
}

void Character::decrease_hp(int att, int def) {
  hp_value = (hp_value - att + def);
  return;
}