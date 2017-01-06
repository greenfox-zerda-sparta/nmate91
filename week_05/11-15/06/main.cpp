#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string read_return(string in_string);

int main() {
  // Write a function that reads the content of a file and returns it as a string
  // It should take the filename as a string parameter
  cout << read_return("encyclop.txt") << endl;
  return 0;
}

string read_return(string in_string) {
  ifstream my_file;
  my_file.open(in_string.c_str());
  if (my_file.is_open()) {
    string line;
    stringstream buffer;
    buffer << my_file.rdbuf();
    line = buffer.str();
    cout << line << endl;
    my_file.close();
    return line;
  } else {
    return "There is no file.";
  }
}
