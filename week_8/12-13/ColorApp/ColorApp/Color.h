#pragma once

#include <iostream>
#include <string>

enum Errors { wrong_hexa };

class Color {
public:
  Color();
  Color(Color& other);
  Color(unsigned char, unsigned char, unsigned char);
  Color(std::string&);
  ~Color();
private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

