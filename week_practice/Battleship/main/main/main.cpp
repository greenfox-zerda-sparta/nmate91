#include "stdafx.h"
#include "Board.h"

#define CATCH_CONFIG_MAIN

#ifndef CATCH_CONFIG_MAIN

int main() {
  Board board;
  return 0;
}

#endif // !CATCH_CONFIG_MAIN

#ifdef CATCH_CONFIG_MAIN

#include "catch.hpp"
using namespace std;

TEST_CASE("Is vector ready") {
  Board board;
  REQUIRE(board.getVector().size());
}

TEST_CASE("Is vector coordinate 0") {
  srand(time(NULL));
  Board board;
  REQUIRE(board.getVectorElementByCoordinate(5, 5) == 0);
}

TEST_CASE("Is i, j coordinate setted to 1") {
  srand(time(NULL));
  Board board;
  board.setCoordinateToShip(5, 5, 1);
  REQUIRE(board.getVectorElementByCoordinate(5, 5) == 1);
}

TEST_CASE("Generate x") {
  srand(time(NULL));
  Board board;
  REQUIRE(board.generateX(CARRIER) <= board.getVector().size() - CARRIER);
  REQUIRE(board.generateX(CARRIER) >= 0);
}

TEST_CASE("Generate y") {
  srand(time(NULL));
  Board board;
  REQUIRE(board.generateY(CARRIER) <= board.getVector()[CARRIER].size() - CARRIER);
  REQUIRE(board.generateY(CARRIER) >= 0);
}

TEST_CASE("row free") {
  srand(time(NULL));
  Board board;
  REQUIRE(board.isColFree(board.generateX(CARRIER), board.generateY(CARRIER), CARRIER));
  REQUIRE(board.isRowFree(board.generateX(CARRIER), board.generateY(CARRIER), CARRIER));
}

TEST_CASE("Put down ship") {
  srand(time(NULL));
  Board board;
  board.placeShips(CARRIER);
  board.placeShips(BATTLESHIP);
  board.placeShips(CRUISER);
  board.placeShips(SUBMARINE);
  board.placeShips(DESTROYER);
  REQUIRE(board.getVector().size());

  //just for demonstration purposes:

  for (int i = 0; i < board.getVector().size(); i++) {
    for (int j = 0; j < board.getVector()[i].size(); j++) {
      std::cout << board.getVectorElementByCoordinate(i, j) << " ";
    }
    std::cout << std::endl;
  } 
}

#endif // CATCH_CONFIG_MAIN



