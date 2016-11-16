#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "PrintUsage.h"
#include "FileHandler.h"

using namespace std;

int main(int argc, char *argv[]) {
  print_usage();
  cout << argv[0] << endl;
  FileHandler my_file("asdasdasd.txt");
  return 0;
}
