#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  // Create a program that decrypts the file called "encoded-lines.txt",
  // and pritns the decrypred text to the terminal window.

ifstream file_1;
  file_1.open("dope.txt");
  if (file_1.is_open()) {
    string text;
    stringstream buffer;
    buffer << file_1.rdbuf();
    text = buffer.str();
    string space = " ";
    for (int i = 0; i < text.size(); i++) {
        text.at(i)--;
    }
    cout << text;
  }
  return 0;
}
