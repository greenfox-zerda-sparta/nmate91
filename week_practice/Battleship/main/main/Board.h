#pragma once
#include <iostream>
#include <vector>

class Board {
private:
  std::vector<std::vector<unsigned int>> board_vector;
public:
  Board();
  ~Board();
  std::vector<std::vector<unsigned int>> getVector();
  unsigned int getVectorElementByCoordinate(unsigned int, unsigned int);
  void setCoordinateToShip(unsigned int, unsigned int);
};

