#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

class NumberGenerator {
private:
  std::string digits;
  std::string generated_number;
public:
  NumberGenerator();
  ~NumberGenerator();
  std::string getGeneratedNumber();
  void generateNumber();
  bool isNumberRepeated(char);
};


