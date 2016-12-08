#include "Character.h"


Character::Character() {
}

Character::~Character() {
}

void Character::suffer_attack(int attacker_value) {
  if (hp > 0) {
    hp = hp - attacker_value + dp;
    std::cout << hp << std::endl;
  }
  return;
}

int Character::get_x() {
  return x;
}

int Character::get_y() {
  return y;
}

int Character::get_attack() {
  return sp;
}

void Character::defence_move(std::vector<std::vector<int>>& v) {
  if ((y - 72 > 0) && v[x][y - 72] == 1) {
    y = y - 72;
    return;
  }
  else if ((x - 72 > 0) && v[x - 72][y] == 1) {
    x = x - 72;
    return;
  }
  else if ((y + 72 < 720) && v[x][y + 72] == 1) {
    y = y + 72;
    return;
  }
  else if ((x + 72 < 720) && v[x + 72][y] == 1) {
    x = x + 72;
    return;
  }
  return;
}