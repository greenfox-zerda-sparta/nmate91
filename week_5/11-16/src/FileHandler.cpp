#include "FileHandler.h"
#include <fstream>
#include <iostream>

FileHandler::FileHandler(string file_name) {
  ofstream todo_file;
  todo_file.open(file_name.c_str());
  if (todo_file.is_open()) {
    string text_text = "asdasdad";
    todo_file << text_text + "\n";
    todo_file.close();
  }
  return;
}
