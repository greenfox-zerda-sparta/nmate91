#include <iostream>
#include <algorithm>
using namespace std;

int reverse (int* array, int length) {
  int temp; //ideiglenes tarolasra van
  for (int i = 0; i <= length/2; i++) { //a feleig szamolunk el
    temp = array [length-i-1]; //temp most 8 value
    array[length-i-1] = array [i]; // array[lengthrgkrigr most 1 value
    array [i] = temp; //array[0] pedig 8-as value
  }
  for (int i = 0; i < length; ++i) {
    cout << array[i] << " ";
  }
  return 0;
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int length = sizeof(array)/sizeof(*array);
  reverse (array, length);
  // Write a function that takes an array and its length than reverses the array
  return 0;
}
