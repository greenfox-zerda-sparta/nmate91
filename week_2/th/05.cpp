#include <iostream>

using namespace std;

bool has_n(int *array, int length){
  bool a = 0, b;
  for(int i = 0; i <= length; i++){
    if (array[i] < 0) {
      a = 1;
      return true;
    }
  }
  if (a == 0) {
   b = false;
  }
  return b;
}

int main() {
  int numbers[] = {6, -5, 3, 4, 1, 8, 7};
  int length = sizeof(numbers)/sizeof(*numbers);
  has_n(numbers, length);
  cout << has_n(numbers, length);
  // Write a function that decides if an array includes at least one negative number or not
  return 0;
}
