#include "stdafx.h"
#include "SumClass.h"


SumClass::SumClass() {
}


SumClass::~SumClass() {
}

int SumClass::get_victor_sum(std::vector<int>& victor) {
  int sum = 0;
  for (std::vector<int>::iterator it = victor.begin(); it != victor.end(); it++) {
    sum = sum + *it;
  }
  return sum;
}