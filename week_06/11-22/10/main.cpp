#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"
#include "Exceptions.h"

// Duplicate the Stack class from the previous exercies.
// Create a class for Your exception.
// The class should have two private fields:
// 1.) A filed from Your enum type to represent the kind of error.
// 2.) A field of type: int. So You can give back the element or the index which caused the problems.
//   Why do this? You can five back not only the type of error, but also the element with which it had happened.
//   This is a common way of handling exceptions. Imagine a situation where You receive an object over network
//   to be pushed onto Your stack. This way the exception can include all the information You need to notify
//   the sender about the failure. Or deal with it otherwise.
//
// Set all the fields in the constructor only.
// Create get... methods for both variables.
// Create an std::string toString() method, which gives back a comprehensive error message.
//
// Demonstrate how this works in the main function. Print the error messages from the main function.

int main() {
  Stack my_stack;
  Stack my_stack2;
  try {
    my_stack.push(4);
    my_stack.push(2);
    my_stack.push(6);
    my_stack.push(8);
    my_stack.push(99);
    my_stack.push(8);
    my_stack.push(6);
  }
  catch (MyErrors err) {
    Exceptions something(err);
    cout << something.toString() << "At: " << my_stack.get_index() << endl;
  }

  try {
    my_stack2.pop();
  }
  catch (MyErrors err) {
    Exceptions something2(err);
    cout << something2.toString() << "At: " << my_stack2.get_index() << endl;
  }
  return 0;
}
