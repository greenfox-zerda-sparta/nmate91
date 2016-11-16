#include "PrintUsage.h"

void print_usage() {
  std::cout << "CLI Todo application" << std::endl << "====================" << std::endl << std::endl;
  std::cout << "Command line arguments: " << std::endl << "-l   Lists all the tasks" << std::endl;
  std::cout << "-a   Adds a new task" << std::endl << "-r   Removes an task" << std::endl;
  std::cout << "-c   Completes an task" << std::endl << "Please choose an option!" << std::endl;
  std::cout << "The way to use it: ";
}
