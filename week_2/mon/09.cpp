#include <iostream>
#include <string>

using namespace std;

int main() {
	int i = 1357988018575474;
	if (i % 11 == 0) {
		cout << "This hell of a big number is divisible by 11." << endl;
	} else {
		cout << "This hell of a big number is not divisible by 11.";
	}
	return 0;
}
