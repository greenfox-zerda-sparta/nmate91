#include <iostream>

using namespace std;

// Please allocate a 10 long array and fill it with numbers from 0 to 4, then print the whole array
  // Please delete the array before the program exits

int main() {
  int* pointer = NULL;
  pointer = new int[10];
  for (int i = 0; i <= 9; i++){
    pointer[i] = i;
    cout << pointer[i] << endl;
  }
  delete[] pointer;
  return 0;
}
