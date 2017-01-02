#include "stdafx.h"
#include "sudoku_checker.hpp"
#include <cmath>
#include <algorithm>

bool check_sudoku_row(std::vector<int> v) {
  if (v.size() == 0) {
    return false;
  }
  return is_square_number(v.size()) && is_all_elem_valid(v);
}

bool is_all_elem_valid(std::vector<int> v) {
  std::sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] != i + 1) {
      return false;
    }
  }
  return true;
}

bool is_square_number(int number) {
  return number == sqrt(number) * sqrt(number);
}