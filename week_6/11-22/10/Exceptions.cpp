#include "Exceptions.h"

Exceptions::Exceptions(MyErrors err)
{
  this->class_error = err;
}

string Exceptions::toString() {
  if (class_error == err_a) {
    return "Your stack is full.";
  }
  else if (class_error == err_b) {
    return "Your stack is empty.";
  }
  return "WTF";
}
