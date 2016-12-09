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


void Character::defence_move(Map* map) {
  if ((y - 72 > 0) && map->is_floor(x / 72, (y - 72) / 72)) {
    map->set_map(x / 72, (y - 72) / 72, map_value);
    y = y - 72;
    map->set_map(x / 72, (y + 72) / 72, 1);
    return;
  }
  else if ((x - 72 > 0) && map->is_floor((x - 72) / 72, y / 72)) {
    map->set_map((x - 72) / 72, y / 72, map_value);
    x = x - 72;
    map->set_map((x + 72) / 72, y / 72, 1);
    return;
  }
  else if ((x + 72 < 720) && map->is_floor((x + 72) / 72, y / 72)) {
    map->set_map((x + 72) / 72, y / 72, map_value);
    x = x + 72;
    map->set_map((x - 72) / 72, y / 72, 1);
    return;
  }
  else if ((y + 72 < 720) && map->is_floor(x / 72, (y + 72) / 72)) {
    map->set_map(x / 72, (y + 72) / 72, map_value);
    y = y + 72;
    map->set_map(x / 72, (y - 72) / 72, 1);
    return;
  }
  return;
}