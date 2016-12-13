#include <iostream>
#include <vector>

using namespace std;

// create a function that prints a vector using iterators

void print_using_iterator(vector<int>& v, int number) {
  try {
    if (number > v.size()) {
    	throw "Error";
    }
    vector<int>::iterator it = v.begin() + number;
    for(vector<int>::iterator i = v.begin(); i != it; i++) {
  	  cout << *i << endl;
    }
  }
  catch (string msg) {
  	cerr << msg << endl;
  }
}

int main() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }
  print_using_iterator(v, 5);
  return 0;
}
