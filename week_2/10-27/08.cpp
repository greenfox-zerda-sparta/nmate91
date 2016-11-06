#include <iostream>
#include <string>
using namespace std;

// Create a function that takes a number and prints a triangle like this:
  //
  //      *
  //     ***
  //    *****
  //   *******
  //  *********
  // ***********
  //
  // The triangle should have as many lines as the value in the argument

int print(int h){
  int space = h, star = 1;
  for (int i = 0; i < h; i++) {
    for(int j = 0; j < space; j++) {
          cout << " ";
        }
    for(int j = 0; j < star; j++) {
      cout << "*";
    }
    cout << endl;
    star+=2;
    space--;
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
