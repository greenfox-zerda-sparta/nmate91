#include "stdafx.h"
#include "GameSoul.h"


GameSoul::GameSoul() {
  numberOfGuesses = 10;
  s_thenumber = std::to_string(this->thenumber);
}

void GameSoul::GetGuess(int index) {
  for (int i = index; i < numberOfGuesses; i++) {
    std::cout << "Please enter your guess: " << std::endl;
    std::cin >> guess;
    s_guess = std::to_string(guess);

    if (GameSoul::IsDifferentDigits()) {
      std::cerr << "The given digits should be different! Try again." << std::endl;
      return GameSoul::GetGuess(i);
    }

    if (guess < 1000 || guess > 9999) {
      std::cout << "You must give a number between 1000 and 9999! Please try again: " << std::endl;
      return GetGuess(i);
    }

    if (GameSoul::IsGameWon(guess)) {
      std::cout << "WIIIIN!!!!" << std::endl;
      return;
    }
    GameSoul::CountBullsCows();
  }
  return;
}

bool GameSoul::IsGameWon(int input_guess) {
  return (input_guess == this->thenumber);
}

void GameSoul::CountBullsCows() {
  for (int i = 0; i < s_guess.length(); i++) {
    for (int j = 0; j < s_thenumber.length(); j++){
      if (s_guess[i] == s_thenumber[j]) {
        if (i == j) {
          bulls++;
          break;
        }
        else {
          cows++;
          break;
        }
      }
    }
  }
  std::cout << "Cows: " << cows << std::endl << "Bulls: " << bulls << std::endl;
  bulls = 0;
  cows = 0;
  return;
}

bool GameSoul::IsDifferentDigits() {
  for (int i = 0; i < s_guess.length(); i++) {
    for (int j = 0; j < s_guess.length(); j++) {
      if (s_guess[i] == s_guess[j] && i != j) {
        return true;
      }
    }
  }
  return false;
}

GameSoul::~GameSoul() {

}
