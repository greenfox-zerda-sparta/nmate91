#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  // Create a program that decrypts the file called "reversed-lines.txt",
  // and pritns the decrypred text to the terminal window.
  ifstream file_1;
  file_1.open("reversed.txt");
  if (file_1.is_open()) {
    string text;
    stringstream buffer;
    buffer << file_1.rdbuf();
    text = buffer.str();
    string temp_text[text.size()];
    for (int i = (text.size() - 1); i >= 0; i--) {
      temp_text[text.size() - 1 - i] = text.at(i);
      cout << temp_text[text.size() - 1 - i];
    }
    file_1.close();
  }
  return 0;
}
