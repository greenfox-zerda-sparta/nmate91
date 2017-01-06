#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class WordToolbox {
public:
  WordToolbox(string);
  ~WordToolbox();
  bool isAnAnagram(string stringToCheck);
  int countHowMany(char charToFind);
  string getS();
  string setS(string);
private:
  string stringHeld;
};

