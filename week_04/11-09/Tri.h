#ifndef TRI_H_
#define TRI_H_
#include <string>
#include "Shape.h"
using namespace std;

class Triangle: public Shape{
public:
  string* getName();
};

#endif /* TRI_H_ */
