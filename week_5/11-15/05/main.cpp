#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream my_file("fifth-exercise.txt");
  if (my_file.is_open()) {
    string a;
    while(my_file >> a) {
      cout << a << endl;
    }
  } else {
    cerr << "Could not open the file.";
    return 2;
  }
  // Write a program that prints a content of a file called "fifth-exercise.txt"
  // If it could not open the file it should write: "Could not open the file" to the standard error
  // The program should return 2 if there where an error

  return 0;
}
