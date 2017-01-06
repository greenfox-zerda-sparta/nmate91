#include <iostream>
#include <string>

using namespace std;

int main() {
	int w = 24;
	int out = 0;
	if (w % 2 == 0) {
		cout << ++out;
	} else {
		cout << "nope";
	}
	// if w is even increment out by one
	return 0;
}
