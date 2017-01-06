#pragma once
#include <iostream>
#include <string>

class GameSoul {
private:
  const int thenumber = 2048;
  int cows = 0;
  int bulls = 0;
  int guess = 0;
  int numberOfGuesses = 0;
  std::string s_guess;
  std::string s_thenumber;
public:
  GameSoul();
  ~GameSoul();
  bool IsGameWon(int);
  bool IsDifferentDigits();
  void CountBullsCows();
  void GetGuess(int);
};