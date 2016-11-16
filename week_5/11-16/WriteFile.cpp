#include "stdafx.h"
#include "WriteFile.h"

WriteFile::WriteFile() {
  
}

WriteFile::~WriteFile() {

}

void WriteFile::add_a_task() {
  string input_text;
  cout << "Your task: " << endl;
  getline(cin, input_text);
  ofstream write_file;
  write_file.open("My_text.txt", ios::app); //ios app new line
  if (write_file.is_open()) {
    write_file << input_text + "\n";
    write_file.close();
  }
  return;
}