#include "stdafx.h"
#include "Color.h"

Color::Color() {
  red = 0;
  green = 0;
  blue = 0;
}

Color::Color(unsigned int r, unsigned int g, unsigned int b) {
  red = r;
  green = g;
  blue = b;
}

Color::Color(std::string hex) throw(ERROR_MESSAGE) {
    if (hex.size() != 7) {
      throw wrong_size_hex_code;
    }
    if (hex[0] != '#') {
      throw hex_begins_with_hash;
    }
    std::string valid_chars = { "#abcdefABCDEF0123456789" };
    for (int i = 0; i < hex.size(); i++) {
      if (valid_chars.find(hex[i]) == std::string::npos) {
        throw hex_code_not_valid;
      }
    }
    this->hex_code = hex;
}

int Color::get_red() {
  return red;
}

int Color::get_green() {
  return green;
}

int Color::get_blue() {
  return blue;
}

void Color::set_red(int value) {
  red = value;
  return;
}

void Color::set_green(int value) {
  green = value;
  return;
}

void Color::set_blue(int value) {
  blue = value;
  return;
}

int Color::convert_hex_to_decimal(char a, char b) {
  int decimal;
  if (a == '0') {
    decimal = b - '0';
  }
  else if (isdigit(a)) {
    if (isdigit(b)) {
      decimal = 16 * (a - '0') + (b - '0');
    }
    else if (isalpha(b)) {
      decimal = 16 * (a - '0') + 10 + (b - 'A');
    }
  }
  else if (isalpha(a)) {
    if (isdigit(b)) {
      decimal = 16 * (10 + (a - 'A')) + (b - '0');
    }
    else if (isalpha(b)) {
      decimal = 16 * (10 + (a - 'A')) + 10 + (b - 'A');
    }
  }
  return decimal;
}

void Color::hex_to_rgb() {
  this->red = convert_hex_to_decimal(hex_code[1], hex_code[2]);
  this->green = convert_hex_to_decimal(hex_code[3], hex_code[4]);
  this->blue = convert_hex_to_decimal(hex_code[5], hex_code[6]);
  return;
}

void Color::darken(float value) {
  try {
    if (value < 0 && value > 1) {
      throw invalid_value;
    }
    this->red = red - red * value;
    if (red < 0) { red = 0; }
    this->green = green - green * value;
    if (green < 0) { green = 0; }
    this->blue = blue - blue * value;
    if (blue < 0) { blue = 0; }
  }
  catch (ERROR_MESSAGE) {
    std::cerr << "You gave an invalid value for darkening" << std::endl;
  }
}

void Color::lighten(float value) {
  try {
    if (value < 0 && value > 1) {
      throw invalid_value;
    }
    this->red = red + red * value;
    if (red < 255) { red = 255; }
    this->green = green + green * value;
    if (green < 255) { green = 255; }
    this->blue = blue + blue * value;
    if (blue < 255) { blue = 255; }
  }
  catch (ERROR_MESSAGE) {
    std::cerr << "You gave an invalid value for lightening" << std::endl;
  }
}

Color& Color::operator++() {
  lighten(0.1);
  return *this;
}

Color& Color::operator--() {
  darken(0.1);
  return *this;
}