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
    string greet() {
      return "Hello my name is: " + this->name;;
  }
};

int main() {
  // Create a method on the Student class called "greet" that returns a string
  // like: "Hello my name is: <student name>"
  Student greet("Princess Consuela Bananahammock", 21);
  cout << greet.greet();
  return 0;
}
