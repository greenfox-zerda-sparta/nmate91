#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
//create a vector of integers with the size of 10, fill them with random numbers
//create a vector of doubles and reserve place for 10 items
//push and item to the end of the vector with the double places
//print which vectors size is higher (and why?)
  vector<int>int_vector(10);
  for (int i = 0; i < int_vector.size(); i++){
    int_vector[i] = rand() % 100;
  }
  vector<double>d_vector;
  d_vector.reserve(10);
  d_vector.push_back(1);
  cout << "int: " << int_vector.size() << "double: " << d_vector.size() << endl;
  return 0;
}

//int should be higher, because with the reserve() method we just reserve a place in the memory, but it's not a size, it's just capacity
