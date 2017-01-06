#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character {
public:
  Character();
  ~Character();
  int attack();
  int defence();
  int get_hp();
  void decrease_hp(int, int);
protected:
  string name = "";
  string char_type = "";
  int hp_value;
  int attack_value;
  int def_value;

};

