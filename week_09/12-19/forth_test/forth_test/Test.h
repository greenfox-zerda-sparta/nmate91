#include "catch.hpp"
#include "WordToolbox.h"

TEST_CASE("Apple string", "[get string]") {
  WordToolbox wSource("Tarzan's toenails");
  REQUIRE(wSource.countHowMany('a') == 3);
  REQUIRE(wSource.countHowMany('T') == 2);
  REQUIRE(wSource.countHowMany('t') == 2);
  REQUIRE(wSource.countHowMany('x') == 0);
  REQUIRE(wSource.countHowMany(' ') == 1);
}

TEST_CASE("lofasz", "[anyad]") {
  WordToolbox bizbasz("asd fgh");
  REQUIRE_FALSE(bizbasz.isAnAnagram("das    ghf") != true);
}

TEST_CASE("hat jo", "[cool]") {
  WordToolbox test("asd fgh");
  REQUIRE(test.isAnAnagram("das    ghf") == true);
}

TEST_CASE("set and get", "[set_get]") {
  WordToolbox test2("asd");
  REQUIRE(test2.getS() == test2.setS("das"));
}
