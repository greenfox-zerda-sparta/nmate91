#include <iostream>
#include <string>
// create a function that returns it's input factorial
using namespace std;
int factorial(int n) {
  if(n > 1){
    return n * factorial(n - 1);
} else {
    return 1;
}
	cout << n;
	return 0;
}
int main() {
	int n;
	cout << "Gimme the number: ";
	cin >> n;
	cout << factorial(n);
  return 0;
}
