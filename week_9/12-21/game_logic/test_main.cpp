#ifdef TEST

#include <iostream>
#include <vector>

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "board.hpp"

using namespace std;

TEST_CASE("Is vector ready") {
  Board board;
  REQUIRE(board.get_vector().size());
}

TEST_CASE("Set vector is cool") {
  Board board1;
  REQUIRE(board1.get_vector() == board1.player_1_sets_cell(4, 5));
}

TEST_CASE("Set vector2 is cool") {
  Board board2;
  REQUIRE(board2.get_vector() == board2.player_2_sets_cell(5, 5));
}

TEST_CASE("is set valid?") {
  Board board3;
  board3.player_1_sets_cell(5, 5);
  REQUIRE(!board3.is_cell_empty(5, 5));
}

#endif
