#include <iostream>
#include <string>

using namespace std;

int main() {
	int k = 1521;
	if (k%3 || k%5){
		cout << "devidable";
	} else {
		cout << "nope";
	}
	// tell if k is dividable by 3 or 5
	return 0;
}
