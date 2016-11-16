#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "PrintUsage.h"
#include "FileHandler.h"
#include "WriteFile.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argv[0][0]) {
    print_usage();
    cout << argv[0] << endl;
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
    print_usage();
  }
  return 0;
}
