#include "stdafx.h"
#include "Color.h"

int main() {
  try {
    Color new_color("#59A27A");
    new_color.hex_to_rgb();
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
  return 0;
}

