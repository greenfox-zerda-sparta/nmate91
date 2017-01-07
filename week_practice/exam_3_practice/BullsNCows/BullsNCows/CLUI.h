#pragma once
#include <iostream>
#include <string>
#include "GameLogic.h"

#define MAX_GUESS 5

class CLUI {
private:
  int guesscounter;
  GameLogic* gamelogic;

public:
  CLUI();
  ~CLUI();
  void takeUserGuess();
};

