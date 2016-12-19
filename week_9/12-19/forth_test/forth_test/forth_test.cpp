// forth_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "WordToolbox.h"

#ifndef CATCH_CONFIG_MAIN

int main() {
  WordToolbox w("folate");
  w.setS("folate");
  string alternatives[6] = { "falsetto", "latest", "foetal","aloft","float","flota" };
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " << w.isAnAnagram(alternatives[i]) << endl;
  }
  cout << endl << "New test" << endl;
  w.setS("aloft");
  for (int i = 0; i < 6; ++i) {
    cout << "is " << alternatives[i] << " an anagram of " << w.getS() << " = " << w.isAnAnagram(alternatives[i]) << endl;
  }
  return 0;
}

#endif

#ifdef CATCH_CONFIG_MAIN

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

#endif

