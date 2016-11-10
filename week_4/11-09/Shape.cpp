/*
 * Shape.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: matenemeth
 */
#include <string>
#include "Shape.h"
using namespace std;

string* Shape::getName() {
  return new string("Generic Shape");
}
