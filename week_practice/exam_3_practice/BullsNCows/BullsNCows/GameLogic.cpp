#include "stdafx.h"
#include "GameLogic.h"

GameLogic::GameLogic() {
  game = new NumberGenerator;
  game->generateNumber();
}

GameLogic::~GameLogic() {
  delete game;
}

void GameLogic::setUserNumber(std::string input) {
  usernumber = input;
  return;
}

std::string GameLogic::getUserNumber() {
  return usernumber;
}

bool GameLogic::isBull(char digit, int place) {
  for (int i = 0; i < game->getGeneratedNumber().length(); i++) {
    if (digit == game->getGeneratedNumber()[i] && i == place) {
      return true;
    }
  }
  return false;
}

bool GameLogic::isCow(char digit, int place) {
  for (int i = 0; i < game->getGeneratedNumber().length(); i++) {
    if (digit == game->getGeneratedNumber()[i] && i != place) {
      return true;
    }
  }
  return false;
}

bool GameLogic::isWon() {
  return countBulls() == 4;
}

int GameLogic::countBulls() {
  int counter = 0;
  for (int i = 0; i < usernumber.length(); i++) {
    if (isBull(usernumber[i], i)) {
      counter++;
    }
  }
  return counter;
}

int GameLogic::countCows() {
  int counter = 0;
  for (int i = 0; i < usernumber.length(); i++) {
    if (isCow(usernumber[i], i)) {
      counter++;
    }
  }
  return counter;
}