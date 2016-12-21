#include "board.hpp"

Board::Board() {
  vector<vector<unsigned int>> new_vector(19, vector<unsigned int>(19));
  this->board_vector = new_vector;
}

vector<vector<unsigned int>> Board::get_vector() {
  return this->board_vector;
}
