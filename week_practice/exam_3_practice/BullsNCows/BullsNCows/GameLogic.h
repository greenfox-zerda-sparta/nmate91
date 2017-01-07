#pragma once
#include "NumberGenerator.h"
#include <iostream>

class GameLogic {
private:
  NumberGenerator* game;
  std::string usernumber;
public:
  GameLogic();
  ~GameLogic();
  void setUserNumber(std::string);
  std::string getUserNumber();
  bool isBull(char, int);
  bool isCow(char, int);
  bool isWon();
  int countBulls();
  int countCows();
};

