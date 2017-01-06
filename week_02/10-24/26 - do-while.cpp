#include <iostream>
#include <string>

using namespace std;

int main() {
	int i=1;
	do {
		i++;
		if (i % 3 == 0 && i % 5 == 0){
					cout << "FizzBuzz ";
				} else if (i % 3 == 0){
					cout << "Fizz ";
				} else if (i % 5 == 0){
					cout << "Buzz ";
				} else {
					cout << i << " ";
				}
	} while (i<=100);
	return 0;
}
