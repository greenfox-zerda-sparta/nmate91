#include <iostream>

using namespace std;

/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int* resize(int* array, int size, int new_size){
  int* new_array = new int[new_size];
  for (int i = 0; i < new_size; i++) {
    if (i < size) {
      new_array[i] = array[i];
    }
    else {
      new_array[i] = 0;
    }
  }
  for (int i = 0; i < new_size; i++){
    cout << new_array[i] << " ";
  }
  delete array;
  array = NULL;
  return new_array;
}

int main() {
  int* arr = new int[5];
  int new_size;
  for (int i = 0; i < 5; i++) {
    arr[i] = i;
  }
  cout << "Please, give me the new size!" << endl;
  cin >> new_size;
  resize(arr, 5, new_size);
  return 0;
}
