#include <iostream>
#include <string>
// increment the 3rd element, than print all the elements of the array
using namespace std;

int main() {
	int e[] = {1, 2, 3, 4, 5};
	++e[2];
	for (int i = 0; i <=4; i++)
		    cout << e[i]<< endl;

  return 0;
}
