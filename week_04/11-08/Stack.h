#ifndef STACK_H_
#define STACK_H_
using namespace std;

class Stack {
public:
  Stack(unsigned int first_number);
  unsigned int size();
  void push(unsigned int value);
  unsigned int pop();
private:
  int* array = new int;
  int size_of_array;
};

#endif /* STACK_H_ */
