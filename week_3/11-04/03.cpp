//============================================================================
// Name        : 03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Vector {
  double* array;
  unsigned int size;
};

Vector* vector_construct(double input[], int size);
double vector_at(Vector& v, unsigned int index);
void vector_insert(Vector& v, unsigned int index, double value);
unsigned int vector_find(Vector& v, double value);
void vector_remove(Vector& v, unsigned int index);
Vector* vector_concat(Vector& v1, Vector& v2);

int main() {
  double array[] = {1, 2, 3};
  double array2[] = {5, 6, 7};
  int size = sizeof(array)/sizeof(*array);
  int size2 = sizeof(array2)/sizeof(*array2);
  Vector* test_vector = vector_construct(array, size);
  Vector* test_vector2 = vector_construct(array2, size2);
  for (unsigned int i = 0; i < test_vector->size; i++){
    cout << test_vector->array[i] << " ";
  }
  cout << endl << vector_at(*test_vector, 2) << endl;
  vector_insert(*test_vector, 1, 29);
  for (unsigned int i = 0; i < test_vector->size; i++){
    cout << test_vector->array[i] << " ";
  }
  cout << endl << vector_find(*test_vector, 29) << endl;
  vector_remove(*test_vector, 0);
  for (unsigned int i = 0; i < test_vector->size; i++){
    cout << test_vector->array[i] << " ";
  }
  cout << endl;
  Vector* concated_shit = vector_concat(*test_vector, *test_vector2);
  for (unsigned int i = 0; i < concated_shit->size; i++){
    cout << concated_shit->array[i] << " ";
  }
  return 0;
}

Vector* vector_construct(double input[], int num_size) {
  Vector* new_vector = new Vector;
  new_vector->size = num_size;
  new_vector->array = new double[num_size];
  for (int i = 0; i < num_size; i++){
    new_vector->array[i] = input[i];
  }
  return new_vector;
}

double vector_at(Vector& v, unsigned int index) {
  if (index >= v.size){
    return 0;
  } else {
    double value = v.array[index];
    return value;
  }
}

void vector_insert(Vector& v, unsigned int index, double value) {
  double* new_array = new double[v.size + 1];
  for (unsigned int i = 0; i < index; i++) {
    new_array[i] = v.array[i];
  }
  new_array[index] = value;
  for (unsigned int i = index + 1; i <= v.size; i++) {
    new_array[i] = v.array[i-1];
  }
  delete[] v.array;
  v.array = new_array;
  v.size++;
}

unsigned int vector_find(Vector& v, double value) {
  for (unsigned int i = 0; i < v.size; i++){
    if (value == v.array[i]) {
      return i;
    }
  }
  return 0;
}

void vector_remove(Vector& v, unsigned int index) {
  double* new_array = new double[v.size - 1];
  for (unsigned int i = 0; i < index; i++) {
    new_array[i] = v.array[i];
  }
  for (unsigned int i = index; i < v.size - 1; i++) {
    new_array[i] = v.array[i+1];
  }
  delete[] v.array;
  v.array = new_array;
  v.size--;
}

Vector* vector_concat(Vector& v1, Vector& v2) {
  Vector* concatedshit = new Vector;
  concatedshit->size = v1.size + v2.size;
  concatedshit->array = new double[concatedshit->size];
  for (unsigned int i = 0; i < v1.size; i++) {
    concatedshit->array[i] = v1.array[i];
  }
  for (unsigned int i = v1.size; i < concatedshit->size; i++) {
    concatedshit->array[i] = v2.array[i - v1.size];
  }
  return concatedshit;
}
