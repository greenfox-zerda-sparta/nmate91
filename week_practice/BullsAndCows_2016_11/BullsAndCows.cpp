#include "stdafx.h"
#include "Functions.h"
#include "GameSoul.h"
#include "vld.h"

int main() {
  bool playagain;
  do {
    GameSoul new_game;
    PrintIntro();
    new_game.GetGuess(0);
    playagain = AskIfPlayAgain();
  }
  while (playagain == true);
  return 0;
}