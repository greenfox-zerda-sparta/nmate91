#include <iostream>

// Create a constatn using a prepocesor directive.
// Print it out to the console.
// Undefine it. And then redefine it with a new value.
// Print it out again.

#define A 100

int main() {
  std::cout << A << std::endl;
  #undef A
  #define A 299
  std::cout << A << std::endl;
  return 0;
}