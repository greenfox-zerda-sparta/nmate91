#include "stdafx.h"
#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "SumClass.h"

TEST_CASE("Vector test", "[vector]") {
  SumClass anyad;
  std::vector<int> victor(5, 5);
  REQUIRE(anyad.get_victor_sum(victor) == 25);
}


