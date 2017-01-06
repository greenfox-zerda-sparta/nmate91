#include <iostream>
#include <string>
#include "Stack.h"
#include "MyErrors.h"

using namespace std;

// Create a fixed size stack. The stack can contain only 5 elements.
// You can push on the stack and pop from the stack.
// Write the push and pop methods so, that each throws an integer value if there is an error.
// Like when the stack is empty or full. Just make sure those are different values.
// Write a method called string interpretException(int exception) that returns the error message string for the integer.
//
// Illustrate in the main function both when it works fine and when exceptions occur.

string interpretException(MyErrors err);

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
  catch (MyErrors err) {
    cout << interpretException(err) << endl;
  }

  try {
    Stack my_stack2;
    my_stack2.pop();
  }
  catch (MyErrors err) {
    cout << interpretException(err) << endl;
  }
  return 0;
}

string interpretException(MyErrors err_ex) {
  if (err_ex == err_a) {
      return "Your stack is full.";
    }
    else if (err_ex == err_b) {
      return "Your stack is empty.";
    }
  return "WTF";
}
