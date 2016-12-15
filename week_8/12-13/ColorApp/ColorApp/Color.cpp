#include "stdafx.h"
#include "Color.h"

#include "Util.h"


Color::Color() : red(0), green(0), blue(0) {

}

Color::Color(unsigned char _red, unsigned char _green, unsigned char _blue) : red(_red), green(_green), blue(_blue) {
 
}


Color::Color(Color& other) {
  red = other.red;
  green = other.green;
  blue = other.blue;
}

Color::Color(std::string& hex_code) {
  try {
    if (hex_code.length() != 7 || is_hex_code_invalid(hex_code)) {
      throw wrong_hexa;
    }
    std::cout << "Your hexa is: " << hex_code << std::endl;
  }
  catch (Errors) {
    std::cerr << "Wrong hexa code." << std::endl;
  }
}

Color::~Color() {

}
