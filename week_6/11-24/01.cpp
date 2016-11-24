#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  //create an integer vector with the size of 5 and print the 3rd element of it
  vector<int>my_vector(5);
  my_vector[2] = 321;
  cout << my_vector[2] << endl;
  return 0;
}
