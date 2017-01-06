#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

int main() {
  //Create a vector of integers
  //reserve place for 10 element, then fill those place with random numbers between 0 and 10
  vector<int>my_vector(10);
  for (int i = 0; i < 10; i++) {
    my_vector[i] = rand() % 10;
    cout << my_vector[i] << endl;
  }
  return 0;
}
