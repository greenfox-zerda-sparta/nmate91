#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
//create a vector of integers with the size of 20
//fill this vector with random numbers from 0 to 10
//print the items of the vector
//remove the even numbers, then print the items again 
  vector<int>my_vector(20);
  for (int i = 0; i < my_vector.size(); i++) {
    my_vector[i] = rand() % 11;
    cout << "Before: " << my_vector[i] << endl;
  }
  for (int i = 0; i < my_vector.size(); i++) {
    if (my_vector[i] % 2 == 0) {
      my_vector.erase(my_vector.begin() + i);
    } else {
      cout << "After: " << my_vector[i] << endl;
    }
  }
  return 0;
}
