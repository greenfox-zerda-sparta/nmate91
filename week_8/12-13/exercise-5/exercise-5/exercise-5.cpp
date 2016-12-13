#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

// Write a program that creates a text file named alice_words.txt
// containing an alphabetical listing of all the words,
// and the number of times each occurs, in the text version of
// Alice’s Adventures in Wonderland.
// How many times does the word alice occur in the book?
// What is the longest word in Alice in Wonderland?
// How many characters does it have?

string read_text(map<string, int>& my_map);
void fill_map(map<string, int>& my_map, string word);

int main() {
  map<string, int> my_map;
  string text = read_text(my_map);
  for (map<string, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
    cout << it->first << " lofasz " << it->second << endl;
  }
  return 0;
}

string read_text(map<string, int>& my_map) {
  string word = "";
  ifstream my_file;
  my_file.open("alice.txt");
  while (my_file >> word) {
    fill_map(my_map, word);
  }
  my_file.close();
  return word;
}

void fill_map(map<string, int>& my_map, string word) {
  if (my_map.count(word)) {
    my_map[word]++;
  }
  else {
    my_map[word] = 1;
  }
  return;
}