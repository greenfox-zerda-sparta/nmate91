#include "board.hpp"

Board::Board() {
  vector<vector<Markers>> new_vector(19, vector<Markers>(19, EMPTY));
  this->board_vector = new_vector;
  this->current_marker_type = EMPTY;
}

vector<vector<Markers>> Board::get_vector() {
  return this->board_vector;
}

vector<vector<Markers>> Board::player_1_sets_cell(unsigned int i, unsigned int j) {
  if (is_out_of_range(i, j)) {
    return board_vector;
  }
  if(is_cell_empty(i, j)) {
    this->board_vector[i][j] = PLAYER_1;
    return board_vector;
  }
  return board_vector;
}

vector<vector<Markers>> Board::player_2_sets_cell(unsigned int i, unsigned int j) {
  if (is_out_of_range(i, j)) {
   return board_vector;
  }
  if(is_cell_empty(i, j)) {
    this->board_vector[i][j] = PLAYER_2;
    return board_vector;
  }
  return board_vector;
}

bool Board::is_cell_empty(unsigned int i, unsigned int j) {
  if(board_vector[i][j] != 0) {
    return false;
  }
  return true;
}

bool Board::is_out_of_range(unsigned int i, unsigned int j) {
  if (i >= this->board_vector.size()) {
    return true;
  }
  else if (j >= this->board_vector.size()) {
    return true;
  }
  return false;
}

Markers Board::get_marker_type(unsigned int i, unsigned int j) {
  if(is_out_of_range(i, j)) {
    return OUT_OF_RANGE;
  }
  return this->board_vector[i][j];
} 

bool Board::is_a_player_on_cell(unsigned int i, unsigned int j) {
  if(get_marker_type(i, j) == PLAYER_1) {
    return true;
  }
  else if(get_marker_type(i, j) == PLAYER_2) {
    return true;
  }
  return false;
}

bool Board::are_five_in_a_row(unsigned int i, unsigned int j) {
  if(is_a_player_on_cell(i, j)) { 
    const unsigned int base_i = i;
    unsigned int counter = 0;
    Markers this_marker = get_marker_type(i, j);
    while(i != base_i + 5) {
      if(get_marker_type(i, j) == this_marker) {
        counter++;
      }
      i++;
    }
    if(counter == 5) {
      return true;
    }
  }
  return false;
}
