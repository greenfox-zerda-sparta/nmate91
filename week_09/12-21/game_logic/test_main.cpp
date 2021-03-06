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

TEST_CASE("is out of matrix range") {
  Board board5;
  REQUIRE(board5.is_out_of_range(20, 5)); 
  REQUIRE(board5.is_out_of_range(5, 20));
}

TEST_CASE("player 1 set is not overwritten by player 2, and not out of range") {
  Board board6;
  REQUIRE(board6.player_1_sets_cell(20, 5) == board6.get_vector());
  REQUIRE(board6.player_2_sets_cell(5, 20) == board6.get_vector());
}

TEST_CASE("Get the marker type") {
  Board board7;
  board7.player_1_sets_cell(5, 5);
  REQUIRE(board7.get_marker_type(5, 5) == PLAYER_1);
  REQUIRE(board7.get_marker_type(3, 22) == OUT_OF_RANGE);
}

TEST_CASE("check rows") {
  Board board8;
  board8.player_1_sets_cell(5, 5);
  board8.player_1_sets_cell(6, 5);
  board8.player_1_sets_cell(7, 5);
  board8.player_1_sets_cell(8, 5); 
  board8.player_1_sets_cell(9, 5);
  REQUIRE(board8.get_marker_type(5, 5) == PLAYER_1);
  REQUIRE(board8.are_five_in_a_row(PLAYER_1, 5, 5) == true);
  REQUIRE(board8.is_won(PLAYER_1) == true);
}

TEST_CASE("is given marker type check") {
  Board board9;
  board9.player_1_sets_cell(5, 5);
  board9.is_given_marker_type(PLAYER_1, 5, 5);
}

#endif
