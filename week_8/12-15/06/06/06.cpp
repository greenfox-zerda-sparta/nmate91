#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int number_of_antlers(unsigned int n) {
  n--;
  int antlers;
  if (n % 2 == 0) {
    antlers = 2;
  }
  else if (n % 2 == 1) {
    antlers = 3;
  }
  if (n == 0) {
    return antlers;
  }
  return antlers + number_of_antlers(n);
}

int main() {
  // We have reindeers standing in a line, numbered 1, 2, ... The odd reindeers 
  // (1, 3, ..) have the normal 2 antlers. The even reindeers (2, 4, ..) we'll say 
  // have 3 antlers, because they each have a raised branch (how funny they are, arent they?).  
  // Recursively return the number of "antlers" in the reindeer line 1, 2, ... n (without loops or 
  // multiplication).

  cout << number_of_antlers(10);

  return 0;
}