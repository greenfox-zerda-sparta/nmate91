#include "stdafx.h"
#include "Functions.h"

void PrintIntro() {
  std::cout << "Welcome to Bulls and Cows, a fun word game. " << std::endl;
  std::cout << "Can you guess the 4 length number I'm thinking of?" << std::endl;
  std::cout << std::endl;
  std::cout << "GL HF" << std::endl;
  std::cout << std::endl;
}

bool AskIfPlayAgain() {
  std::cout << "Do you want to play again? (y/n) " << std::endl;
  std::string answer;
  std::cin >> answer;
  return (answer[0] == 'y' || answer[0] == 'Y');
}