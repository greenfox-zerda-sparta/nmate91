#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "PrintUsage.h"
#include "FileHandler.h"
#include "WriteFile.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    print_usage();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'a') {
    WriteFile write_my_file;
    write_my_file.add_a_task();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'l') {
    FileHandler read_my_file;
    read_my_file.read_file();
  }
  else {
    cerr << "Wrong argument." << endl << endl;
    print_usage();
    return 1;
  }
  return 0;
}
