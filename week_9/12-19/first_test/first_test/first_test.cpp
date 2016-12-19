#include "stdafx.h"
#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "Fruit.h"

TEST_CASE("Apple string", "[get string]") {
  Fruit fruit;
  REQUIRE(fruit.getApple() == "apple");
}