#include "board.hpp"

Board::Board() {
  vector<vector<unsigned int>> new_vector(19, vector<unsigned int>(19, 0));
  this->board_vector = new_vector;
}

vector<vector<unsigned int>> Board::get_vector() {
  return this->board_vector;
}

vector<vector<unsigned int>> Board::player_1_sets_cell(unsigned int i, unsigned int j) {
  this->board_vector[i][j] = 1;
  return board_vector;
}

vector<vector<unsigned int>> Board::player_2_sets_cell(unsigned int i, unsigned int j) {
  this->board_vector[i][j] = 2;
  return board_vector;
}

bool Board::is_cell_empty(unsigned int i, unsigned int j) {
  if(board_vector[i][j] != 0) {
    return false;
  }
  return true;
}
