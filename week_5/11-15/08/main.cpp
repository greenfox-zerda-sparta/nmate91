#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool copy_file_to_file(string file_name_1, string file_name_2);

int main() {
  // Write a function that copies a file to an other
  // It should take the filenames as parameters
  // It should return a boolean that shows if the copy was successful
  cout << copy_file_to_file("encyclop.txt", "jigglypuff.txt");
  return 0;
}

bool copy_file_to_file(string file_name_1, string file_name_2) {
  ifstream file_1;
  file_1.open(file_name_1.c_str());
  if (file_1.is_open()) {
    string line;
    stringstream buffer;
    buffer << file_1.rdbuf();
    line = buffer.str();
    file_1.close();

    ofstream file_2;
    file_2.open(file_name_2.c_str());
    file_2 << line;
    file_2.close();

    ifstream file_3;
    file_3.open(file_name_2.c_str());
    string new_line;
    stringstream new_buffer;
    new_buffer << file_3.rdbuf();
    new_line = new_buffer.str();
    if (new_line == line) {
      return true;
    }
  }
  return false;
}
