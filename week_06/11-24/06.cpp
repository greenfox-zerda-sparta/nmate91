#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void suvi_function(vector<double>& some_vector);

int main() {
//create a vector of doubles with the size of 30, with every element equal of 1.5
//create functions that takes this vector, pick the last element of it and adding its value to
//an other item from the vector(this item place is random) and remove the last element at the end
//run this function 20 times, then print every element of the vector 
  vector<double>my_vector(30);
  for (int i = 0; i < my_vector.size(); i++) {
    my_vector[i] = 1.5;
  }
  suvi_function(my_vector);
  return 0;
}

void suvi_function(vector<double>& some_vector) {
  for (int i = 0; i < 20; i++) {
    some_vector[some_vector.size() - 1] = some_vector[some_vector.size() - 1] + some_vector[rand() % 29];
  }
  cout << "After 20 rounds: " << some_vector[some_vector.size() - 1] << endl << endl;
  some_vector.pop_back();
  cout << "After 20 rounds, and a pop_back, our last element: " << some_vector[some_vector.size() - 1];
}
