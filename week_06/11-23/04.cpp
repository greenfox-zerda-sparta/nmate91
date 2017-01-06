#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

template<typename M>
void sort_array(M my_array, int size_array) {
  sort(my_array, my_array + size_array, greater<int>());
  for (int i = 0; i < size_array; i++) {
    cout << my_array[i] << endl;
  }
}

int main() {
// create a function template that takes an array and sort it in a descending order
  int array_size = 3;
  int the_array[array_size] = {1, 2, 5};
  sort_array<int*>(the_array, array_size);
  return 0;
}
