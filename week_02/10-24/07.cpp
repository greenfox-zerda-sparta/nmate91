#include <iostream>
#include <string>

using namespace std;

int main() {
	int g1 = 123;
	int g2 = 345;
	bool g3;
	g3 = g1 ?: g2;
	cout << g3;
	return 0;
}
