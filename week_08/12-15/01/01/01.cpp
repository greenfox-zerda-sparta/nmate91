#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int add_numbers(int n) {
  if (n != 0) {
    return n + add_numbers(n - 1);
  }
  return 0;
}

int main() {
  // write a recursive function
  // that takes one parameter: n
  // and adds numbers from 1 to n
  int result = add_numbers(5);
  cout << result;
  return 0;
}