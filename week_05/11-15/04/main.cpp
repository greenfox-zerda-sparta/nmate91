#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  // Open a file called "fourth-exercise.txt"
  // Print all of its lines to the terminal window
  ifstream my_text;
  my_text.open("forth-exercise.txt");
  int i;
  while(my_text >> i) {
    cout << i << endl;
  }
  return 0;
}
