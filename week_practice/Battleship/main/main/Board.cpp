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
  srand(time(NULL));
  int x, y;
  bool invalid_coordinate = true;
  while (invalid_coordinate) {
    x = generateX(ship);
    y = generateY(ship);
    int length = x + ship;
    for (int i = x; i < length; i++) {
      if (board_vector[x][y] != 0) {
        invalid_coordinate = true;
        break;
      }
      invalid_coordinate = false;
    }
    length = y + ship;
    for (int i = y; i < length; i++) {
      if (board_vector[x][y] != 0) {
        invalid_coordinate = true;
        break;
      }
      invalid_coordinate = false;
    }
  }
  board_vector[x][y];
  bool decide = rand() % 2;
  if (decide) {
    int length = y + ship;
    while (y < length) {
      setCoordinateToShip(x, y, ship);
      y++;
    }
  }
  else {
    int length = x + ship;
    while (x < length) {
      setCoordinateToShip(x, y, ship);
      x++;
    }
  }
}

int Board::generateX(int ship) {
  int x = rand() % 10 - ship;
  if (x < 0) {
    x = 0;
  }
  return x;
}

int Board::generateY(int ship) {
  int y = rand() % 10 - ship;
  if (y < 0) {
    y = 0;
  }
  return y;
}