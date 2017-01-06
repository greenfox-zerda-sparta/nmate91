#include "Tri.h"
#include <iostream>
#include <string>
using namespace std;

Tri::Tri(unsigned int length_input) {
  this->length = length_input;
  this->counter = 1;
}

void Tri::draw_triangle() {
  for (unsigned int i = this->length; i > 0; i--) {
    for (unsigned int j = 0; j < this->counter; j++) {
      cout << '*';
    }
    cout << endl;
    this->counter++;
  }
}

