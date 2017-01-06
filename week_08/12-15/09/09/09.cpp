#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string put_star(string word, int digit) {
  if (digit >= word.length()) {
    return word;
  }
  if (word[digit] == '*') {
    return put_star(word, digit + 1);
  }
  else {
    word.insert(digit + 1, 1, '*');
    return put_star(word, digit + 1);
  }
}

int main() {
  // Given a string, compute recursively a new string where all the
  // adjacent chars are now separated by a "*".
  cout << put_star("starwarsrougeone", 0);
  return 0;
}
