#include "stdafx.h"

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "sudoku_checker.hpp"
using std::vector;

TEST_CASE("empty vector returns false") {
  vector<int> victor;
  REQUIRE_FALSE(check_sudoku_row(victor));
}

TEST_CASE("vector filled from 1 to 4 returns true") {
  vector<int> victor = { 1, 2, 3, 4 };
  REQUIRE(check_sudoku_row(victor));
}

TEST_CASE("vector filled with wrong number of elements returns false") {
  vector<int> victor = { 1, 2, 3 };
  REQUIRE_FALSE(check_sudoku_row(victor));
}

TEST_CASE("vector filled with 1 returns true") {
  vector<int> victor = { 1 };
  REQUIRE(check_sudoku_row(victor));
}

TEST_CASE("vector cannot contain 0") {
  vector<int> victor = { 0 };
  REQUIRE_FALSE(check_sudoku_row(victor));
}

TEST_CASE("vector cannot contain 0 anywhere") {
  vector<int> victor = { 1, 0, 0, 0};
  REQUIRE_FALSE(check_sudoku_row(victor));
}

TEST_CASE("vector cannot contain a number more than once") {
  vector<int> victor = { 1, 1, 2, 4 };
  REQUIRE_FALSE(check_sudoku_row(victor));
}