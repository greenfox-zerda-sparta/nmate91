#include "stdafx.h"
#include "Board.h"

Board::Board() {
  std::vector<std::vector<unsigned int>> new_vector(10, std::vector<unsigned int>(19, 0));
  this->board_vector = new_vector;
}

Board::~Board() {
}

std::vector<std::vector<unsigned int>> Board::getVector() {
  return this->board_vector;
}

unsigned int Board::getVectorElementByCoordinate(unsigned int i, unsigned int j) {
  return this->board_vector[i][j];
}

void Board::setCoordinateToShip(unsigned int i, unsigned int j) {
  this->board_vector[i][j] = 1;
}