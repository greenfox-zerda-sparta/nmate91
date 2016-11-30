#include "stdafx.h"
#include "Functions.h"
#include "GameSoul.h"

int main() {
  bool playagain;
  do {
    PrintIntro();
    GetGuess(0);
    playagain = AskIfPlayAgain();
  }
  while (playagain == true);

  return 0;
}

