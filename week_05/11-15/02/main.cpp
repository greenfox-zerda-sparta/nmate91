#include <iostream>
#include <fstream>

using namespace std;

int main() {
  // Open a file called "second-exercise.txt"
  // Read the content of the file and print it to the terminal window
  ifstream my_file;
  my_file.open("first-exercise.txt");
  string file_content;
  my_file >> file_content;
  my_file.close();
  cout << file_content;
  return 0;
}
