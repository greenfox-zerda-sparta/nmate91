#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string remove_x(string word, int digit) {
  if (digit >= word.length()) {
    return word;
  }
  if (word[digit] == 'x') {
    word.erase(word.begin() + digit);
    return remove_x(word, digit);
  }
  digit++;
  return remove_x(word, digit);
}

int main() {
  // Given a string, compute recursively a new string where all the 'x' chars have been removed.
  cout << remove_x("xxanyadxxx", 0);
  return 0;
}
