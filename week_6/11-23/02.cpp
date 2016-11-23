#include <iostream>
#include <string>

using namespace std;

template<typename M>
void add_elements(M my_array) {
  cout << "Before: " << my_array[2] << endl;
  my_array[2] = my_array[2] + my_array[0];
  cout << "After: " << my_array[2] << endl;
}

int main() {
// create a function template that takes fix long array
// and add the 1st element of it to the third
  int the_array[3] = {1, 2, 5};
  add_elements<int*>(the_array);
  return 0;
}
