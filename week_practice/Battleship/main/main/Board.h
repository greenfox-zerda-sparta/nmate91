#pragma once
#include <iostream>
#include <vector>
#include <time.h>

#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define SUBMARINE 3
#define DESTROYER 2

class Board {
private:
  std::vector<std::vector<unsigned int>> board_vector;
public:
  Board();
  ~Board();
  std::vector<std::vector<unsigned int>> getVector();
  unsigned int getVectorElementByCoordinate(unsigned int, unsigned int);
  void setCoordinateToShip(unsigned int, unsigned int, int);
  void placeShips(int);
  int generateX(int);
  int generateY(int);
  bool isRowFree(int, int, int);
  bool isColFree(int, int, int);
};

