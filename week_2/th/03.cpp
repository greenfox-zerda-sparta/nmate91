#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *first, int *second){
  swap(*first, *second);
}

int main() {
  int first = 12;
  int second = 54;
  cout << first << endl << second << endl;
  swap(first, second);
  cout << first << endl << second << endl;
  // Write a function that takes two int pointers and swaps the values where the pointers point
  return 0;
}
