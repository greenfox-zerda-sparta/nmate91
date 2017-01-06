#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

// write a function that takes a string and returns a map
// the map should have the letters of the string as keys and 
// it should have integers as values that represents how many times the
// letter appeared int the string

map<char, int> get_map(string text) {
  map<char, int> my_map;
  for (int i = 0; i < text.size(); i++) {
    if (my_map.find(text[i]) != my_map.end()) {
      my_map[text[i]]++;

    }
    else {
      my_map[text[i]] = 1;
    }
  }
  return my_map;
}

int main() {
  map<char, int> my_map = get_map("gtfo lol gg wp asd bb");
  for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
    cout << it->first << "; " << it->second << endl;
  }
  return 0;
}