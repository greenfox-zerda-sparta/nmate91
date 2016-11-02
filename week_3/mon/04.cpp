#include <iostream>
#include <stdlib.h>
using namespace std;

int* range(int from, int to, int step){
  int size = abs(to - from / step);
  int* arr = new int[size];
  int counter = 0;
  for (int i = 0; i < size; i++){
    arr[i] = from + (step * counter);
    cout << arr[i] << " ";
    counter++;
  }
  return arr;
}

/**
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's parameters.
 * It should take 3 parameters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
  int from, to, step;
  cout << "From which number?" << endl;
  cin >> from;
  cout << "To which number?" << endl;
  cin >> to;
  cout << "Steps? (if the from is bigger, please write a negative number!" << endl;
  cin >> step;
  range(from, to, step);
  return 0;
}
