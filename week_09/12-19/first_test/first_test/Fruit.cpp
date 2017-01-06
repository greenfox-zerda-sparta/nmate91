#include "stdafx.h"
#include "Fruit.h"


Fruit::Fruit() {
  this->fruit = "apple";
}


Fruit::~Fruit() {
}

std::string Fruit::getApple() {
  return fruit;
}