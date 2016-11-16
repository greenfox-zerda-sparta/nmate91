#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <string>

using namespace std;

class FileHandler {
public:
  FileHandler();
  virtual ~FileHandler();
  void read_file();
};

#endif // FILEHANDLER_H