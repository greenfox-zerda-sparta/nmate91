#pragma once
#include <iostream>
#include <cstdint>

enum ERROR_MESSAGE { wrong_size_hex_code, hex_begins_with_hash, 
  hex_code_not_valid, invalid_value };

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
  void set_red(int);
  void set_green(int);
  void set_blue(int);
  int convert_hex_to_decimal(char, char);
  void hex_to_rgb();
  void darken(float);
  void lighten(float);
  Color& Color::operator++();
  Color& Color::operator--();
  Color& Color::operator*(float);
};

