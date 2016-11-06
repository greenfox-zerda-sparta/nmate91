#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int j1 = 10;
	int j2 = 3;
	if (j1 > pow(j2,2) && j1 < pow(j2,3)) {
		cout << "j1 is between the square and the cube of j2.";
		} else {
			cout << "j1 is not between the square and the cube of j2.";
	}
	return 0;
}
