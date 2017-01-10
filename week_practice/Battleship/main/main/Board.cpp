#include "stdafx.h"
#include "Board.h"

Board::Board() {
  std::vector<std::vector<unsigned int>> new_vector(10, std::vector<unsigned int>(10, 0));
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

void Board::setCoordinateToShip(unsigned int i, unsigned int j, int x) {
  this->board_vector[i][j] = x;
}

void Board::placeShips(int ship) {
  int x, y;
  while (1) {
    x = generateX(ship);
    y = generateY(ship);
    if (isRowFree(x, y, ship)) {
      int length = x + ship;
      while (x < length) {
        setCoordinateToShip(x, y, ship);
        x++;
      }
      break;
    }
    if (isColFree(x, y, ship)) {
      int length = y + ship;
      while (y < length) {
        setCoordinateToShip(x, y, ship);
        y++;
      }
      break;
    }
  }
}

int Board::generateX(int ship) {
  int x = rand() % 10 - ship;
  if (x < 0) {
    return generateX(ship);
  }
  return x;
}

int Board::generateY(int ship) {
  int y = rand() % 10 - ship;
  if (y < 0) {
    return generateY(ship);
  }
  return y;
}

bool Board::isRowFree(int x, int y, int ship) {
  int length = x + ship;
  for (int i = x; i <= length; i++) {
    if (board_vector[i][y] != 0) {
      return false;
    }
  }
  return true;
}

bool Board::isColFree(int x, int y, int ship) {
  int length = y + ship;
  for (int i = y; i <= length; i++) {
    if (board_vector[x][i] != 0) {
      return false;
    }
    return true;
  }
}