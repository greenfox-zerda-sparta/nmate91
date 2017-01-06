#include "stdafx.h"

#define CATCH_CONFIG_MAIN 

#include <iostream>
#include <string>
#include <vector>
#include "catch.hpp"

using namespace std;

int fibonacci(vector<unsigned int>& in_fib_vector, unsigned int i, unsigned int n) {
  vector<unsigned int> fib_vector = in_fib_vector;
  if (i == n) {
    return fib_vector[(fib_vector.size() - 1)];
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

TEST_CASE("FIBO", "[fibonacci]") {
  vector<unsigned int> v;
  REQUIRE(fibonacci(v, 0, 4) == 5);
  REQUIRE(fibonacci(v, 0, 9) == 55);
  REQUIRE(fibonacci(v, 0, 14) == 610);
  REQUIRE(fibonacci(v, 0, 19) == 6765);
}

