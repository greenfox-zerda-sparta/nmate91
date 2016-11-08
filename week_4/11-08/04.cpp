#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }
    void setname(string x) {
         name = x;
       }
    string greet() {
      return "Hello my name is: " + this->name;
    }
};

int main() {
  // Create a method on student that takes a string as an argument and
  // changes it's name property
  Student set_name("John", 21);
  cout << set_name.greet() << endl;
  set_name.setname("Princess Consuela Bananahammock");
  cout << set_name.greet();
  return 0;
}
