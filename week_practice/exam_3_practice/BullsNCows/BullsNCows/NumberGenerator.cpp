#include "stdafx.h"
#include "NumberGenerator.h"


NumberGenerator::NumberGenerator() {
  digits = { "0123456789" };
}

NumberGenerator::~NumberGenerator() {

}

std::string NumberGenerator::getGeneratedNumber() {
  return generated_number;
}

void NumberGenerator::generateNumber() {
  generated_number.push_back(digits[rand() % 9 + 1]);
  for (int i = 1; i < 4; i++) {
    char generated_char = digits[rand() % 10];
    if (isNumberRepeated(generated_char)) {
      i--;
    }
    else {
      generated_number.push_back(generated_char);
    }
  }
  return;
}

bool NumberGenerator::isNumberRepeated(char digit) {
  for (int i = 0; i < generated_number.length(); i++) {
    if (generated_number[i] == digit) {
      return true;
    }
  }
  return false;
}