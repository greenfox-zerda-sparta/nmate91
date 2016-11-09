#include <iostream>
#include <string>
using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }
};

int main() {
  Student person("John", 21);
  return 0;
}
