#pragma once
#include <iostream>
#include <string>

class GameSoul {
private:
  int thenumber = 0;
public:
  GameSoul();
  ~GameSoul();
  bool IsGameWon(int);
  void CountBullsCows(int);
};