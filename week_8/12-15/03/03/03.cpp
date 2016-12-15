#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int power_function(unsigned int base,  unsigned int n) {
  if (n == 0) {
    return 1;
  }
  return base * power_function(base, n - 1);
}

int main() {
  // Given base and n that are both 1 or more, compute recursively (no loops)
  // the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
  cout << power_function(3, 4);
  return 0;
}
