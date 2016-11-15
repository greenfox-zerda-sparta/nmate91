#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_string_to_file(string file_name, string text);

int main() {
  // Write a function that writes a string to a file
  // It should take the filename and the content as a string parameter
  write_string_to_file("asd.txt", "lol asd gg bb wp");
  return 0;
}

void write_string_to_file(string file_name, string text) {
  ofstream my_file;
  my_file.open(file_name.c_str());
  my_file << text;
  my_file.close();
}
