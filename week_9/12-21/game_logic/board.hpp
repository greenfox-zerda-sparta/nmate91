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
  unsigned int player_1_sets_cell();
  unsigned int player_2_sets_cell();
};

#endif
