#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

int main() {
    // Create a `Circle` class that takes it's radius as cinstructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area
  Circle circ(5);
  cout << circ.get_circumference() << endl << circ.get_area() << endl;
  return 0;
}
