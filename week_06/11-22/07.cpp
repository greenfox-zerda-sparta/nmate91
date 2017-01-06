#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

string function(int number) throw (int, const char*) {
  if (number > 5) {
    throw (number - 5);
  }
  else if (number < 0) {
    throw "This is a negative number";
  }
  const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};
  return sentence[number];
}

int main() {
try {
  function(3);
  function(-4);
  function(6);
}
  catch(const char* a) {
    cout << a << endl;
  }
  catch(int b) {
    cout << "You are higher by: " << b << endl;
  }
  return 0;
}

