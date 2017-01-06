#include <iostream>

using namespace std;

int main() {
  int high_number = 2;
  int low_number = 6655;

  int* high_number_pointer = &high_number;
  int* low_number_pointer = &low_number;
  cout << "before high: " << high_number << endl << "before low: " << low_number <<endl;
  int* xhigh_number_pointer = low_number_pointer;
  int* xlow_number_pointer = high_number_pointer;
  low_number_pointer = xlow_number_pointer;
  high_number_pointer = xhigh_number_pointer;
  cout << "high: " << *high_number_pointer << endl << "low: " << *low_number_pointer;

  // Please fix the problem and swap the value of the variables,
  // without using the "high_number" and the "low_number" variables.
  return 0;
}
