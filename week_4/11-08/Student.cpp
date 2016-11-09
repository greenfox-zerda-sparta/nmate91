#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, unsigned int first_grade) {
  this->name = name;
  this->grades[0] = first_grade;
}
void Student::add_grade(int grade_in){
  if (grade_in > 5 || grade_in < 1) {
    cout << "wrong";
    return;
  }
  int* new_grades = new int[size + 1];
  for (int i = 0; i < size; i++) {
    new_grades[i] = grades[i];
  }
  new_grades[size] = grade_in;
  size++;
  delete[] grades;
  grades = new_grades;
}

double Student::get_avg() {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += grades[i];
  }
  return sum / size;
}

