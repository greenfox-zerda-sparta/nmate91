/*
 * Car.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: matenemeth
 */

#include "Car.h"

Car::Car(int km_in, string type_in) {
  this->km = km_in;
  this->type = type_in;
}
int Car::get_km() {
  return km;
}
void Car::run(int km_run) {
  km = km + km_run;
}
