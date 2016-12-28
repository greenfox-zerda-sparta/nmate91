#include "stdafx.h"
#include "Color.h"

enum ERROR_MESSAGE { wrong_size_hex_code, hex_begins_with_hash, hex_code_not_valid };

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

Color::Color(std::string hex) {
  try {
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
  catch (ERROR_MESSAGE error) {
    if (error = wrong_size_hex_code) {
      std::cerr << "The length of your hex code is not valid." << std::endl;
    }
    else if (error = hex_begins_with_hash) {
      std::cerr << "Your hex code shoud begin with a #." << std::endl;
    }
    else if (error = hex_code_not_valid) {
      std::cerr << "You are using wrong characters for your hex code." << std::endl;
    }
  }
}

Color::~Color() {
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
  std::cout << red << std::endl;
  std::cout << green << std::endl;
  std::cout << blue << std::endl;
  return;
}

/* else if ((hex_code[1] - '0') < 10 && (hex_code[1] - '0') > 0) {
    if ((hex_code[2] - '0') < 10 && (hex_code[2] - '0') > 0) {
      this->red = 16 * (hex_code[1] - '0') + (hex_code[2] - '0');
    }
    else if ((hex_code[2]))
  }
  else if ((hex_code[1]))*/