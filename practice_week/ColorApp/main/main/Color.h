#pragma once
#include <iostream>

enum ERROR_MESSAGE { wrong_size_hex_code, hex_begins_with_hash, hex_code_not_valid };

class Color {
private:
  unsigned int red;
  unsigned int green;
  unsigned int blue;
  std::string hex_code;
public:
  Color();
  Color(unsigned int, unsigned int, unsigned int);
  Color(std::string) throw(ERROR_MESSAGE);
  int get_red();
  int get_green();
  int get_blue();
  int convert_hex_to_decimal(char, char);
  void hex_to_rgb();
};

