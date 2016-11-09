#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main() {
    // Create a `Stack` class that stores elements
    // It should have a `size` method that returns number of elements it has
    // It should have a `push` method that adds an element to the stack
    // It should have a `pop` method that returns the last element form the stack and also deletes it from it
  Stack my_stack(20);
  cout << my_stack.size() << endl;
  my_stack.push(32);
  cout << my_stack.size() << endl;
  my_stack.push(22);
  cout << my_stack.size() << endl;
  cout << my_stack.pop() << endl;
  cout << my_stack.size() << endl;
  return 0;
}
