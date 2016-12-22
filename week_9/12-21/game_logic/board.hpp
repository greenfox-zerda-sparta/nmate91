#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

enum Markers {EMPTY, PLAYER_1, PLAYER_2, OUT_OF_RANGE};

class Board {
private:
  vector<vector<Markers>> board_vector;
  Markers current_marker_type;
public:
  Board();
  vector<vector<Markers>> get_vector();
  vector<vector<Markers>> player_1_sets_cell(unsigned int, unsigned int);
  vector<vector<Markers>> player_2_sets_cell(unsigned int, unsigned int);
  bool is_cell_empty(unsigned int, unsigned int);
  bool is_out_of_range(unsigned int, unsigned int);
  Markers get_marker_type(unsigned int, unsigned int);
  bool is_a_player_on_cell(unsigned int, unsigned int);
  bool are_five_in_a_row(unsigned int, unsigned int);
};

#endif
