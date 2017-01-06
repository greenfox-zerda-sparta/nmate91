#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  //create an integer vector with the size of 5 and print all elements of it
  vector<int>my_vector(5);
  for (int i = 0; i < 5; i++) {
    my_vector[i] = i*2;
    cout << my_vector[i] << endl;
  }
  return 0;
}
