#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

class Exceptions
{
  public:
    Exceptions(MyErrors);
    string toString();
  private:
    MyErrors class_error;
};

#endif // EXCEPTIONS_H
