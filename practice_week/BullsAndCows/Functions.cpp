#include "stdafx.h"
#include "Functions.h"

void PrintIntro() {
  std::cout << "Welcome to Bulls and Cows, a fun word game. " << std::endl;
  std::cout << "Can you guess the 4 length number I'm thinking of?" << std::endl;
  std::cout << std::endl;
  std::cout << "GL HF" << std::endl;
  std::cout << std::endl;
}

void GetGuess(int index) {
  GameSoul new_game;
  int numberOfGuesses = 5;
  int guess;
  for (int i = index; i < numberOfGuesses; i++) {
    std::cout << "Please enter your guess: " << std::endl;
    std::cin >> guess;
    if (guess < 1000 || guess > 9999) {
      std::cout << "You must give a number between 1000 and 9999! Please try again: " << std::endl;
      return GetGuess(i);
    }
    if (new_game.IsGameWon(guess)) {
      std::cout << "WIIIIN!!!!" << std::endl;
      return;
    }
    new_game.CountBullsCows(guess);
  }
  return;
}

bool AskIfPlayAgain() {
  std::cout << "Do you want to play again? (y/n) " << std::endl;
  std::string answer;
  std::cin >> answer;
  return (answer[0] == 'y' || answer[0] == 'Y');
}