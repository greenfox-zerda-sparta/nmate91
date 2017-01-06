#include "stdafx.h"
#include "Fight.h"


Fight::Fight() {
}

Fight::~Fight() {
}

void Fight::fight() {
  do
  {
    int decide_attack = rand() % 2;
    if (decide_attack == 0) {
      monster_attack();
    }
    else {
      player_attack();
    }
    counter++;
    cout << "After round " << counter << ": " << endl;
    cout << "Monster hp: " << mo.get_hp() << endl;
    cout << "Player hp: " << po.get_hp() << endl;
  }
  while (mo.get_hp() > 0 && po.get_hp() > 0);
}

void Fight::monster_attack() {
  po.decrease_hp(mo.attack(), po.defence());
  return;
}

void Fight::player_attack() {
  mo.decrease_hp(po.attack(), mo.defence());
  return;
}