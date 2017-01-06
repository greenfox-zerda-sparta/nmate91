#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
using namespace std;

class Student {
  public:
    Student(string name, unsigned int first_grade);
    void add_grade(int grade_in);
    double get_avg();
  private:
    int size = 1;
    int* grades = new int[1];
    string name;
};

#endif /* STUDENT_H_ */
