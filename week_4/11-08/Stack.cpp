#include "Stack.h"
using namespace std;

Stack::Stack(unsigned int first_number) {
  this->array[0] = first_number;
  this->size_of_array = 1;
}

void Stack::push(unsigned int value) {
  int* new_array = new int[this->size_of_array + 1];
  for (int i = 0; i < this->size_of_array; i++) {
    new_array[i] = this->array[i];
  }
  new_array[this->size_of_array] = value;
  this->size_of_array++;
  delete[] this->array;
  this->array = new_array;
}

unsigned int Stack::pop() {
  int* new_array = new int[this->size_of_array - 1];
  for (int i = 0; i < this->size_of_array - 1; i++) {
    new_array[i] = this->array[i];
  }
  this->size_of_array = this->size_of_array - 1;
  return this->array[this->size_of_array];
  delete[] this->array;
  this->array = new_array;
}

unsigned int Stack::size() {
  return this->size_of_array;
}
