//============================================================================
// Name        : 02.cpp
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
  new_stack->array = new double[2 * new_stack->size];
  for (int i = 0; i < new_stack->size; i++){
    new_stack->array[i] = input[i];
  }
  return new_stack;
}

void stack_push(Stack& stack, double value) {
  stack.array[stack.size] = value;
  stack.size++;
  if (stack.size * 0.8 <= (sizeof(stack.array)/sizeof(*stack.array))) {
    stack_construct(stack.array, stack.size);
  }
}

double stack_pop(Stack& stack) {
    double last_pushed = stack.array[stack.size - 1];
    stack.size--;
    if (stack.size == 0) {
     delete stack.array;
     stack.array = nullptr;
     }
    return last_pushed;
  return -1;
}

int main() {
  double array[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int size = sizeof(array)/sizeof(*array);
  Stack* test_struct = stack_construct(array, size);
  for (int i = 0; i < test_struct->size; i++) {
   cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double b = 8;
  stack_push(*test_struct, b);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double c = 9;
  stack_push(*test_struct, c);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double d = 10;
  stack_push(*test_struct, d);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double e = 11;
  stack_push(*test_struct, e);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double f = 12;
  stack_push(*test_struct, f);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double g = 13;
  stack_push(*test_struct, g);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double h = 14;
  stack_push(*test_struct, h);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double i2 = 15;
  stack_push(*test_struct, i2);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double j = 16;
  stack_push(*test_struct, j);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  double k = 17;
  stack_push(*test_struct, k);
  for (int i = 0; i < test_struct->size; i++) {
    cout << test_struct->array[i] << " ";
  }
  cout << endl;
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  cout << stack_pop(*test_struct) << "; ";
  return 0;
}
