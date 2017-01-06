#include <iostream>
#include <string>

using namespace std;

template<typename M>
void print(M my_array, int size) {
  for (int i = 0; i < size; i++) {
    cout << my_array[i] << endl;
  }
}

int main() {
// create a function template which takes in an array, and the size of it
// print all the elements of the array
  int array_size = 3;
  int the_array[array_size] = {1, 2, 5};
  print<int*>(the_array, array_size);
  return 0;
}
