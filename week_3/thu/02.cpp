#include <string>
#include <iostream>

using namespace std;


struct RectangularCuboid {
  double a;
  double b;
  double c;
};

int get_surface(RectangularCuboid& s) {
  int cub = s.a * s.b * s.c;
  return cub;
}


// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface
// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int main() {
  RectangularCuboid stuffthing;
  stuffthing.a = 3;
  stuffthing.b = 4;
  stuffthing.c = 5;
  cout << get_surface(stuffthing);
  return 0;
}

