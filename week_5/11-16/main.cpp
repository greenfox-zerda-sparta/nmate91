#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "PrintUsage.h"
#include "FileHandler.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
    print_usage();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'l') {
    _l_argument();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'a') {
    _a_argument();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'r') {
    _r_argument();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'c') {
    _c_argument();
  }
  else {
    cerr << "Unsupported argument." << endl << endl;
    print_usage();
    return 1;
  }
  return 0;
}
