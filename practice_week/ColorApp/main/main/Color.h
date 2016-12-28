#pragma once
#include <iostream>

class Color {
private:
  unsigned int red;
  unsigned int green;
  unsigned int blue;
  std::string hex_code;
public:
  Color();
  Color(unsigned int, unsigned int, unsigned int);
  Color(std::string);
  ~Color();
  int convert_hex_to_decimal(char, char);
  void hex_to_rgb();
};

