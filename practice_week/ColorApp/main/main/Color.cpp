#include "stdafx.h"
#include "Color.h"

enum ERROR_MESSAGE { wrong_size_hex_code, hex_begins_with_hash, hex_code_not_valid };

Color::Color() {
  red = 0;
  green = 0;
  blue = 0;
}

Color::Color(unsigned char r, unsigned char g, unsigned char b) {
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
