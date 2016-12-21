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


#endif
