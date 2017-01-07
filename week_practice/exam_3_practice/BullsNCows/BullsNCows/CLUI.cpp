#include "stdafx.h"
#include "CLUI.h"


CLUI::CLUI() {
  std::cout << "WELCOME TO BULLS AND COWS GAME" << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "You have to guess a number between 1000 and 9999." << std::endl;
  std::cout << "The digits are not repeating." << std::endl;
  guesscounter = 0;
  gamelogic = new GameLogic;
}

CLUI::~CLUI() {
  delete gamelogic;
}

void CLUI::takeUserGuess() {
  do {
    std::string usernumber;
    std::cout << "Make your guess! You have " << MAX_GUESS - guesscounter << " guesses left." << std::endl;
    std::cin >> usernumber;
    gamelogic->setUserNumber(usernumber);
    if (gamelogic->isWon()) {
      std::cout << "Congrats, you've won!!!" << std::endl;
      break;
    }
    if (usernumber.length() != 4) {
      guesscounter--;
      std::cout << "Invalid guess, make another one!" << std::endl;
    }
    else {
      std::cout << "Bulls:" << gamelogic->countBulls() << " Cows:" << gamelogic->countCows() << std::endl;
    }
    guesscounter++;
  } while (guesscounter != MAX_GUESS);
  std::string text;
  std::cout << "Do you want to play again? Type yes or no." << std::endl;
  std::cin >> text;
  if (text == "yes") {
    guesscounter = 0;
    takeUserGuess();
  }
  std::cout << "Bye-bye!!!" << std::endl;
}
