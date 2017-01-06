#include "stdafx.h"
#include "PrintUsage.h"

void print_usage() {
  std::cout << " CLI Todo application" << std::endl << " ====================" << std::endl << std::endl;
  std::cout << " Command line arguments: " << std::endl << " -l   Lists all the tasks" << std::endl;
  std::cout << " -a   Adds a new task" << std::endl << " -r   Removes an task" << std::endl;
  std::cout << " -c   Completes an task" << std::endl << " Please choose an option!" << std::endl;
}

void _a_argument() {
  cout << "Please give me the name of the task!" << endl << endl;
  string input_string;
  getline(cin, input_string);
  FileHandler add_task_to_file;
  add_task_to_file.add_task(input_string);
}

void _l_argument() {
  FileHandler print_to_terminal;
  print_to_terminal.print();
}

void _r_argument() {
  cout << "Please give which index you want to remove!" << endl << endl;
  int index;
  cin >> index;
  FileHandler remove_task_from_file;
  remove_task_from_file.remove_task(index - 1);
}

void _c_argument() {
  cout << "Please give which index you want to complete!" << endl << endl;
  int index;
  cin >> index;
  FileHandler complete_task_from_file;
  complete_task_from_file.make_complete(index - 1);
}