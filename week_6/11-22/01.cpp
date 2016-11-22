#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.

int main() {
  try {
    int b = 0;
    if (b == 0) {
      throw b;
    }
  }
  catch (int c) {
  cout << c << endl;
  }
  return 0;
}

