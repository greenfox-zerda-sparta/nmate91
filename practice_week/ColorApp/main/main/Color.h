#pragma once
#include <iostream>

class Color {
private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  std::string hex_code;
public:
  Color();
  Color(unsigned char, unsigned char, unsigned char);
  Color(std::string);
  ~Color();
};

