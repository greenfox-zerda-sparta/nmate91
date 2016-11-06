#include <iostream>
#include <string>
using namespace std;

// create a function that takes a number and prints a triangle like this:
  // *
  // **
  // ***
  // ****
  // *****
  // ******
  //
  // The triangle should have as many lines as the value in the argument

int print(int h){
  int star = 0;
    for (int i = h; i >= 0; i--) {
      for(int j = 0; j < star; j++) {
        cout << "*";
      }
      cout << endl;
      star++;
    }
    return 0;
}

int main() {
  cout << "Height: ";
  int h;
  cin >> h;
  print (h);
  return 0;
}
