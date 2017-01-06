#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "MyErrors.h"

using namespace std;

class Stack {
public:
  Stack();
  ~Stack();
  int* fixed_array;
  int number_of_elements = 0;
  void push(int number) throw (MyErrors);
  void pop() throw (MyErrors);
};

#endif // STACK_H
