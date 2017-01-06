#include "stdafx.h"
#include "WordToolbox.h"

WordToolbox::WordToolbox(string stringHeld) {
  transform(stringHeld.begin(), stringHeld.end(), stringHeld.begin(), ::tolower);
  this->stringHeld = stringHeld;
}


WordToolbox::~WordToolbox() {
}

string WordToolbox::getS() {
  return this->stringHeld;
}

string WordToolbox::setS(string input_string) {
  this->stringHeld = input_string;
  return this->stringHeld;
}

bool WordToolbox::isAnAnagram(string stringToCheck) {
  transform(stringToCheck.begin(), stringToCheck.end(), stringToCheck.begin(), ::tolower);
  sort(stringToCheck.begin(), stringToCheck.end());
  stringToCheck.erase(remove(stringToCheck.begin(), stringToCheck.end(), ' '), stringToCheck.end());
  sort(stringHeld.begin(), stringHeld.end());
  stringHeld.erase(remove(stringHeld.begin(), stringHeld.end(), ' '), stringHeld.end());
  return stringToCheck == stringHeld;
}

int WordToolbox::countHowMany(char charToFind) {
  charToFind = tolower(charToFind);
  int char_counter = 0;
  for (int i = 0; i < this->stringHeld.length(); i++) {
    if (stringHeld[i] == charToFind) {
      char_counter++;
    }
  }
  return char_counter;
}