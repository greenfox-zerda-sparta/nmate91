#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string x = "monkey";
	if (x.size() > 4){
		cout << "Long!";
	} else {
		cout << "Short!";
	}
	// if the string is longer than 4 characters***
	// print 'Long!' otherwise print 'Short!'
	cout << x.size() << endl << x.length();
	return 0;
}
