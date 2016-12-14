#include <iostream>
#include <string>

std::string valid_chars = "0123456789ABCDEFabcdef";

bool is_hex_code_invalid(std::string code) {
  for (int i = 0; i < code.length(); i++) {
    if (valid_chars.find(code[i]) == -1) {
      return true;
    }
  }
  return false;
}