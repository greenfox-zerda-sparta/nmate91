#include "Stack.h"

Stack::Stack() {
  fixed_array = new int[5];
}

void Stack::push(int number) throw(int) {
  if (number_of_elements > 5) {
    throw - 1;
  }
  fixed_array[number_of_elements] = number;
  number_of_elements++;
}

void Stack::pop() throw(int) {
  if (number_of_elements == 0) {
    throw - 2;
  }
  int* new_fixed_array = new int[5];
  --number_of_elements;
  for (int i = 0; i < number_of_elements; i++) {
    new_fixed_array[i] = fixed_array[i];
  }
  delete[] fixed_array;
  fixed_array = new_fixed_array;
}

Stack::~Stack() {
  delete[] fixed_array;
}
