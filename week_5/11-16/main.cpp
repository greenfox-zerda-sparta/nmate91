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
  else if (argv[1][0] == '-' && argv[1][1] == 'a') {
    string input_string;
    getline(cin, input_string);
    FileHandler add_task_to_file;
    add_task_to_file.add_task(input_string);
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'l') {
    FileHandler print_to_terminal;
    print_to_terminal.print();
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'r') {
    cout << "Pleas give which index you want to delete!" << endl;
    int index;
    cin >> index;
    FileHandler remove_task_from_file;
    remove_task_from_file.remove_task(index - 1);
  }
  else if (argv[1][0] == '-' && argv[1][1] == 'c') {
    cout << "Pleas give which index you want to complete!" << endl;
    int index;
    cin >> index;
    FileHandler complete_task_from_file;
    complete_task_from_file.make_complete(index + 1);
  }
  else {
    cerr << "Wrong argument." << endl << endl;
    print_usage();
    return 1;
  }
  return 0;
}
