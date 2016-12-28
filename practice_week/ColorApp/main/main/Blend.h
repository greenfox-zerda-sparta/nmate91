#pragma once
#include "Color.h"

class Blend {
private:
  Color color1;
  Color color2;
public:
  Blend(Color&, Color&);
  Color make_the_blend();
  Color operator+();
};

