#include <iostream>
#include <string>
#include "Tri.h"
using namespace std;

int main() {
    // Create a triangle class that takes a length parameter and prints a triangle like this:
    //   *
    //   **
    //   ***
    //   ****
    //   *****
    //   ******
    // It should take a number as parameter that describes how many lines the triangle has
  Tri my_triangle(5);
  my_triangle.draw_triangle();
  return 0;
}
