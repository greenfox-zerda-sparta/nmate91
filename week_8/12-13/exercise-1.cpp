#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
  }

  // Print the first 5 elements of the vector using iterators
  
  vector<int>::iterator it = v.begin() + 5;

  for(vector<int>::iterator i = v.begin(); i != it; i++) {
  	cout << *i << endl;
  }
  return 0;
}
