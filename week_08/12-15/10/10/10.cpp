// 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<unsigned int> fibonacci(vector<unsigned int>& in_fib_vector, unsigned int i, unsigned int n) {
  vector<unsigned int> fib_vector = in_fib_vector;
  if (i == n) {
    return fib_vector;
  }
  if (fib_vector.size() == 0) {
    fib_vector.push_back(0);
  }
  if (fib_vector.size() == 1) {
    fib_vector.push_back(1);
  }
  int number;
  number = fib_vector[i] + fib_vector[i + 1];
  fib_vector.push_back(number);
  return fibonacci(fib_vector, i + 1, n);
}

int main() {
  // The fibonacci sequence is a famous bit of mathematics, and it happens to
  // have a recursive definition. The first two values in the sequence are
  // 0 and 1 (essentially 2 base cases). Each subsequent value is the sum of the
  // previous two values, so the whole sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21
  // and so on. Define a recursive fibonacci(n) method that returns the nth
  // fibonacci number, with n=0 representing the start of the sequence.
  vector<unsigned int> in_fib_vector;
  vector<unsigned int> fib_vector = fibonacci(in_fib_vector, 0, 90);
  vector<unsigned int>::iterator it = fib_vector.begin();
  for (it; it != fib_vector.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}