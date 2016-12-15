#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int bunnies_floppy_ears(unsigned int number_of_bunnies) {
  number_of_bunnies--;
  int ears = 2;
  if (number_of_bunnies == 0) {
    return ears;
  }
  return ears + bunnies_floppy_ears(number_of_bunnies);
}

int main() {
  // We have a number of bunnies and each bunny has two big floppy ears.
  // We want to compute the total number of ears across all the bunnies
  // recursively (without loops or multiplication).
  cout << bunnies_floppy_ears(542) << endl;
  return 0;
}

