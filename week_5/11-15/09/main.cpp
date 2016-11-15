#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  // Create a program that decrypts the file called "duplicated-chars.txt",
  // and pritns the decrypred text to the terminal window.
  ifstream file_1;
  file_1.open("encyclop.txt");
  if (file_1.is_open()) {
    string text;
    stringstream buffer;
    buffer << file_1.rdbuf();
    text = buffer.str();
    file_1.close();
    //cout << text << endl;
    int count_chars = text.size();
    for (int i = 0; i < count_chars; i = i + 2) {
      cout << text.at(i);
    }
  }
  return 0;
}
