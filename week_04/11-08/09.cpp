#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
  Student my_student("bela", 4);
  my_student.add_grade(4);
  my_student.add_grade(2);
  my_student.add_grade(1);
  cout << my_student.get_avg();
  return 0;
}
