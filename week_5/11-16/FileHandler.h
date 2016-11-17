#pragma once

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
using namespace std;

class FileHandler {
private:
  int number_of_lines;
  string* tasks = new string[1024];
public:
  FileHandler();
  ~FileHandler();
  void print();
  void add_task(string new_task);
  void remove_task(int index); //not working well
  void make_complete(int index);
};

#endif