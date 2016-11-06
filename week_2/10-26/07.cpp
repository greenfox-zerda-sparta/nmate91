#include <iostream>

using namespace std;

int main() {
  int high_number = 6655;
  int low_number = 2;

  int *high_number_pointer = &low_number;
  int *low_number_pointer = &high_number;
  cout << "before high: " << high_number_pointer << endl << "before low: " << low_number_pointer <<endl;
  int* xhigh_number_pointer = low_number_pointer;
  int* xlow_number_pointer = high_number_pointer;
  low_number_pointer = xlow_number_pointer;
  high_number_pointer = xhigh_number_pointer;
  cout << "hight: " << high_number_pointer << endl << "low: " << low_number_pointer;

  // Please fix the problem and swap where the pointers point,
  // without using the "&" operator.

  return 0;
}
