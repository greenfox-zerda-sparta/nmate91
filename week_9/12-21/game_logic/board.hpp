#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
  vector<vector<unsigned int>> board_vector;
public:
  Board();
  vector<vector<unsigned int>> get_vector();
  vector<vector<unsigned int>> player_1_sets_cell(unsigned int, unsigned int);
  vector<vector<unsigned int>> player_2_sets_cell(unsigned int, unsigned int);
  bool is_cell_empty(unsigned int, unsigned int);
};

#endif
