#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//find how much integer divisor 2400 has
	//create a vector of doubles, reserve place for the divisors of 2400
	//fill this places with random numbers from 0 to 2400
	//sort them in ascending order
  int counter = 0;
  for (int i = 1; i <= 1200; i++) {
    if (2400 % i == 0) {
      counter++;
    }
  }
  vector<double>victor(counter);
  for (int i = 0; i < counter; i++) {
    victor[i] = rand() % 2401;
    cout << victor[i] << "; ";
  }
  cout << endl;
  sort(victor.begin(), victor.end());
  for (int i = 0; i < counter; i++) {
    cout << victor[i] << "; ";
  }
  return 0;
}
