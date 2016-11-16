#include "stdafx.h"
#include "FileHandler.h"
#include <fstream>
#include <iostream>

FileHandler::FileHandler(string file_name) {
  ofstream write_file;
  write_file.open(file_name.c_str());
  if (write_file.is_open()) {
    string text_text = "asdasdad";
    write_file << text_text + "\n";
    write_file.close();
  }
  ifstream read_todo;
  read_todo.open(file_name.c_str());
  if (read_todo.is_open()) {
    int number_of_lines = 0;
    string line;
    while (getline(read_todo, line)) {
      ++number_of_lines;
      string number_line_in_string = to_string(number_of_lines);
      cout << number_line_in_string + " - " + line;
    }
    cout << number_of_lines;
  }
  return;
}