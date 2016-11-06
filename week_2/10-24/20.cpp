#include <iostream>
#include <string>

using namespace std;

int main() {
	int z = 13;
	if (z >= 10 && z <= 20) {
		cout << "Sweet!";
	} else if (z>20) {
		cout << "Less!";
	} else {
		cout << "More!";
	}
	return 0;
}
