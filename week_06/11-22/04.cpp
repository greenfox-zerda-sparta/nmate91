#include <iostream>
#include <string>
using namespace std;

// Write a function that receives a string and an unsigned integer.
// The function should return an array of strings, with two string in it.
// The first string should be the first part of the original string
// Characters in range [0,index-1].
// The second part should be the rest of the string characters range [index,length-1]
// Example: split("Rebarbara", 2)
// Result: {"Re", "barbara"}
// If the index is out of bounds, throw an exception.
//
// In the main function demonstrate the function when working, and when throwing an exception.
// Write the results to the console.

string* function(string text, unsigned int a) throw (const char*) {
  if (a > text.length()) {
    throw "Out of bounds\n";
  }
  string* array_of_strings = new string[2];
  string temp_text_before, temp_text_after;
  for (unsigned int i = 0; i < a; i++) {
    temp_text_before[i] = text[i];
  }
  for (unsigned int i = a; i < text.length(); i++) {
    temp_text_after[i - a] = text[i];
  }
  array_of_strings[0] = temp_text_before;
  array_of_strings[1] = temp_text_after;
  return array_of_strings;
}

int main (){
  try {
    string* x = function("dmspoijmewpoakf", 3);
    string* y = function("ddd", 19);
    delete[] x;
    delete[] y;
  }
  catch (const char* ex) {
    cout << ex << endl;
  }
  return 0;
}
