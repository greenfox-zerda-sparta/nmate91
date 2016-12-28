#include "stdafx.h"
#include "Blend.h"

Blend::Blend(Color& input1, Color& input2) {
  color1 = input1;
  color2 = input2;
}

Color Blend::make_the_blend() {
  Color new_color;
  int new_red = (color1.get_red() + color2.get_red()) / 2;
  new_color.set_red(new_red);
  int new_green = (color1.get_green() + color2.get_green()) / 2;
  new_color.set_green(new_green);
  int new_blue = (color1.get_blue() + color2.get_blue()) / 2;
  new_color.set_blue(new_blue);
  return new_color;
}