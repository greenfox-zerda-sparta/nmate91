#include "stdafx.h"
#include "FileHandler.h"
#include <fstream>
using namespace std;


FileHandler::FileHandler() {
  //beolvasom vele a txt-t, lesz egy array, tasks, amit feltoltok line-stringekkel
  ifstream read_file;
  read_file.open("mytext.txt");
  string line;
  if (read_file.is_open()) {
    number_of_lines = 0;
    while (getline(read_file, line)) {
      tasks[number_of_lines] = line;
      number_of_lines++;
    }
  }
  read_file.close();
}

void FileHandler::make_complete(int index) {
  tasks[index].at(tasks[index].length() - 1) = 'x';
}

void FileHandler::print() {
  for (int i = 0; i < number_of_lines; i++) {
    string temp = tasks[i];
    char lastChar = temp.at(temp.length() - 1);
    temp.erase(temp.length() - 1);
    string count_string = to_string(i + 1);
    cout << count_string + " - " + "[" + lastChar + "] " + temp << endl;
  }
}

void FileHandler::add_task(string new_task) {
  string* new_tasks = new string[1024];
  for (int i = 0; i < number_of_lines; i++) {
    new_tasks[i] = tasks[i];
  }
  new_tasks[number_of_lines] = new_task + ' ';
  number_of_lines++;
  delete[] tasks;
  tasks = new_tasks;
}

void FileHandler::remove_task(int index) {
  string* new_tasks = new string[1024];
  for (int i = 0; i < index; i++) {
    new_tasks[i] = tasks[i];
  }
  for (int i = index + 1; i < number_of_lines; i++) {
    new_tasks[i - 1] = tasks[i];
  }
  number_of_lines--;
  delete[] tasks;
  tasks = new_tasks;
}


FileHandler::~FileHandler() {
  ofstream task_out("mytext.txt");
  for (int i = 0; i < number_of_lines; i++) {
    task_out << tasks[i] << "\n";
  }
  task_out.close();
}
