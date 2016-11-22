#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Write a function that receives a string and a character.
// The function should return an array of strings.
// The function should split the string at the character it receives as the second argument.
// The character it uses to split should not be in any of the new strings.
// Example: split("What a nice day", ' ');
// Result: {"What", "a", "nice",  "day"}
// If the character is not in the string throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.

string* function(string text, char some_char) throw (const char*) {
  int space_count = 0;
  for (int i = 0; i < text.length(); i++) {
    if (some_char == text[i]) {
      space_count++;
    }
  }
  if (space_count == 0) {
    throw "No char like that...";
  }
  stringstream ss;
  ss.str(text);
  int counter = 0;
  string line;
  while (getline(ss, line, ' ')) {
    counter++;
  }
  int i = 0;
  string* array_of_string = new string[counter];
  while (getline(ss, line, ' ')) {
    array_of_string[i] = line;
    i++;
  }
  return array_of_string;
}

int main () {
  try {
    string* a = function("What a nice day!", ' ');
    cout << sizeof(a); //actually it shows, that my array is there
    delete[] a;
  }
  catch (const char* ex) {
    cout << ex << endl;
  }
  return 0;
}
