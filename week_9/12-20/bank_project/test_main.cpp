#ifdef TEST

#include <iostream>

#define CATCH_CONFIG_MAIN

#include "./test_files/catch.hpp"
#include "bank.hpp"

#include <vector>
#include <string>

using namespace std;


TEST_CASE("Get the name") {
  Bank bank("Sir Robin");
  REQUIRE(bank.get_name() == "Sir Robin");
}


TEST_CASE("add amount to balance") {
  Bank bank("Sir Robin");
  REQUIRE(bank.top_up(39.00) == 39.00);
}

#endif
