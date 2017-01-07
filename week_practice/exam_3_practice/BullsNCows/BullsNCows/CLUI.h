#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "GameLogic.h"

#define MAX_GUESS 10

class CLUI {
private:
  int guesscounter;
  GameLogic* gamelogic;

public:
  CLUI();
  ~CLUI();
  void takeUserGuess();
  void writeWinToLogFile();
};

