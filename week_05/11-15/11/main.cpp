#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  // Create a program that decrypts the file called "reversed-order.txt",
  // and pritns the decrypred text to the terminal window.
  ifstream file_1;
  file_1.open("dope.txt");
  if (file_1.is_open()) {
    int number_of_lines = 0;
    string line;
    while (getline(file_1, line)) {
      ++number_of_lines;
    }
    for (int i = number_of_lines; i > 0; i--) {
      getline(file_1, line);
      cout << line << endl;
    }
    file_1.close();
  }
  return 0;
}
