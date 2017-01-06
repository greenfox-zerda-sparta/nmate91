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
string delete_special_char(string);
bool is_char_invalid(char);

int main() {
  map<string, int> my_map;
  string text = read_text(my_map);
  for (map<string, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
    cout << it->first << " || " << it->second << endl;
  }
  return 0;
}

string read_text(map<string, int>& my_map) {
  string word = "";
  string temp = "";
  ifstream my_file;
  my_file.open("alice.txt");
  while (my_file >> word) {
    temp = delete_special_char(word);
    fill_map(my_map, temp);
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

string delete_special_char(string word) {
  string temp;
  for (int i = 0; i < word.length() - 1; i++) {
    if (is_char_invalid(word[i])) {
      word.erase(word.begin() + i);
      temp = word;
      return delete_special_char(temp);
    }
  }
  return word;
}

bool is_char_invalid(char letter) {
  if (letter == ',') {
    return true;
  }
  else if (letter == '.') {
    return true;
  }
  else if (letter == '!') {
    return true;
  }
  else if (letter == ';') {
    return true;
  }
  else if (letter == ';') {
    return true;
  }
  else if (letter == '?') {
    return true;
  }
  else if (letter == '/') {
    return true;
  }
  else if (letter == '(') {
    return true;
  }
  else if (letter == ')') {
    return true;
  }
  return false;
}