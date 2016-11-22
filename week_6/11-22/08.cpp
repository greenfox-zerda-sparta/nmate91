#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.
// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

int main() {
  try {
    Stack my_stack;
    my_stack.push(4);
    my_stack.push(2);
    my_stack.push(6);
    my_stack.push(8);
    my_stack.push(99);
    my_stack.push(8);
    my_stack.push(6);
  }
  catch (int a) {
    if (a == -1) {
      cout << "Your stack is full." << endl;
    } else if (a == -2) {
      cout << "Your stack is empty." << endl;
    }
  }
  try {
    Stack my_stack2;
    my_stack2.pop();
  }
  catch (int a) {
    if (a == -1) {
      cout << "Your stack is full." << endl;
    } else if (a == -2) {
      cout << "Your stack is empty." << endl;
    }
  }
  return 0;
}

