#include <iostream>
#include <string>
// create a function that doubles it's input
// double j with it

using namespace std;
int sayNumber(int number) {
	cout << 2*number;
	return 2*number;
}

int main() {
  int j = 123;
  sayNumber(j);
  return 0;
}
