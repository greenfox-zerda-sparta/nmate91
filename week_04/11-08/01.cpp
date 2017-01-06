#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
};

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21

  Student John;
  John.name = "John";
  John.age = 21;
  return 0;
}
