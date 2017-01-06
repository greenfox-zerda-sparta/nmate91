#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */


float avg(float sum, int how_many){
  float avg_value;
  avg_value = sum / how_many;
  return avg_value;
}

int main() {
  cout << "How many numbers would you like to work with?" << endl;
  int how_many, input_number;
  float sum;
  cin >> how_many;
  float* pointer = new float[how_many];
  for (int i = 0; i < how_many; i++) {
    cout << "Alright, please enter the numbers; " << endl;
    cin >> input_number;
    pointer[i] = input_number;
  }
  for (int i = 0; i < how_many; i++){
    sum = sum + pointer[i];
  }
  cout << avg(sum, how_many);
  delete[] pointer;
  return 0;
}
