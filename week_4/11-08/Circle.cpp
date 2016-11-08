/*
 * Circle.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: matenemeth
 */

#include "Circle.h"
using namespace std;


Circle::Circle (double rad_in) {
  this->radius = rad_in;
}
double Circle::get_circumference() {
    return 2*radius*3.14;
  }
double Circle::get_area() {
    return radius*radius*3.14;
  }
