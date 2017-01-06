#include <iostream>

using namespace std;

int myarray(int a[], int length) {
  for (int i = 0; i <= length; i++){
    a[i] = i;
    cout << a[i] << " ";
  }
  return *a;
}

int main() {
  int array[10];
  int length = sizeof(array)/sizeof(int);
  myarray(array, length);
  // write a function that takes an array and a length and it fills the array
  // with numbers from zero till the length
  return 0;
}
