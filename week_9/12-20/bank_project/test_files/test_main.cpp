#ifdef TEST

#include <iostream>

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../bank.hpp"

#include <vector>
#include <string>

using namespace std;


TEST_CASE("Get the name") {
  Bank bank("Sir Robin");
  REQUIRE(bank.get_name() == "Sir Robin");
}

TEST_CASE("Get balance") {
  Bank bank("Sir Robin");
  REQUIRE(bank.get_balance() == 0);
}

TEST_CASE("add amount to balance") {
  Bank bank("Sir Robin");
  REQUIRE(bank.top_up(39.00) == 39.00);
}

TEST_CASE("transfer test") {
  Bank bank1("Sir Robin");
  Bank bank2("Apple Cinnamon");
  bank1.top_up(30.00);
  bank2 = bank1.transfer(bank2, 20.01);
  REQUIRE(bank1.get_balance() == Approx(9.99));
  REQUIRE(bank2.get_balance() == Approx(20.01));
}

TEST_CASE("create bond") {
  Bank bank1("Sir Robin");
  bank1.top_up(49.00);
  bank1.create_a_new_bond(20.00, 0.01);
  REQUIRE(bank1.get_balance() == 29.00);
}

TEST_CASE("bond has interest") {
  Bank bank("Sir Robin");
  bank.top_up(444.00);
  bank.create_a_new_bond(20.00, 0.02);
  REQUIRE(bank.has_bond_yearly_interest());
}

#endif
