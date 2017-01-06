#include <iostream>
#include <string>

using namespace std;

template<typename M>
void print(M my_array) {
  cout << my_array[0] << endl;
}

int main() {
// create a function template the takes in a fix long array and prints the 1st element of it
  int the_array[3] = {1, 2, 5};
  print<int*>(the_array);
  return 0;
}
