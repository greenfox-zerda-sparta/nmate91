#include <iostream>
#include <string>
// print the sum of all numbers in h
using namespace std;

int main() {
  int h[] = {3, 4, 5, 6, 7};
  int sum=0;
  for (int i=0; i<=4; i++){
	  sum+=h[i];
  }
  cout << sum;
  return 0;
}
