//============================================================================
// Name        : 01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
using namespace std;

// Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
// Please delete the array before the program exits

int main() {
  int* pointer = NULL;
  pointer = new int[5];
  for (int i = 0; i <= 4; i++) {
    pointer[i] = i;
    cout << pointer[i] << endl;
  }
  delete[] pointer;
  cin.get();
  return 0;
}
