#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <string>

using namespace std;

class FileHandler {
private:
  int number_of_lines = 0;
public:
  FileHandler();
  virtual ~FileHandler();
  void read_file();
  int get_line_number();
};

#endif // FILEHANDLER_H