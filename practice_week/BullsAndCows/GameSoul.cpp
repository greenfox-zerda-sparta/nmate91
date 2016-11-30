#include "stdafx.h"
#include "GameSoul.h"


GameSoul::GameSoul() {
  this->thenumber = std::rand() % 9999 + 1000;
}

bool GameSoul::IsGameWon(int input_guess) {
  return (input_guess == this->thenumber);
}

void GameSoul::CountBullsCows(int input_guess) {
  std::string s_input_guess = std::to_string(input_guess);
  std::string s_thenumber = std::to_string(this->thenumber);
  int cows = 0;
  int bulls = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++){
      if (s_input_guess[i] == s_thenumber[j]) {
        if (i == j) {
          bulls++;
        }
        else {
          cows++;
        }
      }
    }
  }
  std::cout << "Cows: " << cows << std::endl << "Bulls: " << bulls << std::endl;
  return;
}

GameSoul::~GameSoul() {
}
