#include <iostream>
#include <string>
#include <vector>
using namespace std;

void add_char(vector<char>& my_vector);

int main() {
	//create a vector of chars with the size of zero;
	//write a function where the user can add characters to the end of this vector
  vector<char>char_vector(0);
  add_char(char_vector);
  cout << char_vector[0];
  return 0;
}

void add_char(vector<char>& my_vector) {
  char input;
  cout << "Give me a char, biatccch!" << endl;
  cin >> input;
  my_vector.push_back(input);
}
