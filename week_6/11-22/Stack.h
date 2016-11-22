#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
  Stack();
  ~Stack();
  int* fixed_array;
  int number_of_elements = 0;
  void push(int number) throw (int);
  void pop() throw (int);
};

#endif // STACK_H
