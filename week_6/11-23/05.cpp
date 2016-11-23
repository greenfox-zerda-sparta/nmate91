#include <iostream>
#include <string>

using namespace std;

template<typename M, typename N>
void print(M my_array_1, N my_array_2, int size_1, int size_2) {
  if (sizeof(*my_array_1) == sizeof(*my_array_2)) {
    cerr << "They are the same size. " << sizeof(*my_array_2) << " = " << sizeof(*my_array_1) << endl;
  }
  else if (sizeof(*my_array_1) > sizeof(*my_array_2)) {
    for (int i = 0; i < size_1; i++) {
    cout << my_array_1[i] << endl;
    }
  }
  else if (sizeof(*my_array_1) < sizeof(*my_array_2)) {
    for (int i = 0; i < size_2; i++) {
    cout << my_array_2[i] << endl;
    }
  }
}

int main() {
  //Create a function template that takes 2 different typenames, and prints out
  //which one is stored in more bytes from then
  int array_size_1 = 3;
  int array_size_2 = 3;
  int int_array[array_size_1] = {1, 2, 5};
  double double_array[array_size_2] = {1.2, 2.4, 5.5};
  print<int*, double*>(int_array, double_array, array_size_1, array_size_2);
  return 0;
}
