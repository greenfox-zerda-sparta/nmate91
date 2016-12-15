#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string make_x_y(string word, int digit) {
  if (digit == word.length()) {
    return word;
  }
  if (word[digit] == 'x') {
    word[digit] = 'y';
  }
  digit++;
  return make_x_y(word, digit);
}

int main() {
  // Given a string, compute recursively (no loops) a new string where all the
  // lowercase 'x' chars have been changed to 'y' chars.
  cout << make_x_y("xxxxx", 0);
  return 0;
}