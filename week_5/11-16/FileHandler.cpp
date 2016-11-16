#include "stdafx.h"
#include "FileHandler.h"
#include "PrintUsage.h"
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

FileHandler::FileHandler() {
  
}

FileHandler::~FileHandler() {

}

void FileHandler::read_file() {
  ifstream read_todo;
  read_todo.open("My_text.txt");
  if (read_todo.is_open()) {
      int number_of_lines = 0;
      string line;
      while (getline(read_todo, line)) {
        ++number_of_lines;
        string number_line_in_string = to_string(number_of_lines);
        cout << number_line_in_string + " - " + line << endl;
    }
    return;
  } 
  return;
}