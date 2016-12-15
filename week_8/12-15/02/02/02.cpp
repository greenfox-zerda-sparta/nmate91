#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int sum_of_digits(unsigned int n) {
  if (n == 0) {
    return 0;
  }
  int current_digit;
  current_digit = n % 10;
  n = n / 10;
  return current_digit + sum_of_digits(n);
}

int main() {
  // Given a non-negative int n,
  // return the sum of its digits recursively (no loops).
  // Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6),
  // while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
  cout << sum_of_digits(532) << endl;
  return 0;
}