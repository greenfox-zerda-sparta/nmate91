//============================================================================
// Name        : 01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Stack {
  double* array;
  int size;
}test_struct;

Stack* stack_construct(double input[], int num_size) {
  Stack* new_stack = new Stack;
  new_stack->size = num_size;
  new_stack->array = new double[num_size];
  for (int i = 0; i < num_size; i++){
    new_stack->array[i] = input[i];
  }
  return new_stack;
}

void stack_push(Stack& stack, double value) {
  double* new_array = new double[stack.size + 1];
  for (int i = 0; i < stack.size; i++) {
    new_array[i] = stack.array[i];
  }
  new_array[stack.size] = value;
  stack.size++;
  delete[] stack.array;
  stack.array = new_array;
}

double stack_pop(Stack& stack) {
  if (stack.size > 0) {
    double last_pushed = stack.array[stack.size - 1];
    double* new_array = new double[stack.size - 1];
    for (int i = 0; i < stack.size - 1; i++) {
      new_array[i] = stack.array[i];
    }
    stack.size--;
    delete[] stack.array;
    stack.array = new_array;
    if (stack.size == 0) {
     delete stack.array;
     stack.array = nullptr;
    }
    return last_pushed;
  }
  return -1;
}

const bool is_this_empty(Stack& stack) {
  if (stack.array == nullptr ) {
      return true;
    }
  return false;
}

void print_out(double* array, int size) {
  for (int i = 0; i < size; i++) {
      cout << array[i] << " ";
  }
}

int main() {
 double array[] = {0, 1, 2};
 int size = sizeof(array)/sizeof(*array);
 Stack* test_struct = stack_construct(array, size);
 print_out(test_struct->array, test_struct->size);
 cout << endl;
 double b = 4;
 stack_push(*test_struct, b);
 print_out(test_struct->array, test_struct->size);
 cout << endl;
 cout << stack_pop(*test_struct) << endl;
 cout << stack_pop(*test_struct) << endl;
 cout << stack_pop(*test_struct) << endl;
 cout << stack_pop(*test_struct) << endl;
 cout << stack_pop(*test_struct) << endl;
 cout << is_this_empty(*test_struct) << endl;
 for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
 delete test_struct;
 return 0;
}
