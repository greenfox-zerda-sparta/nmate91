#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Cars {
private:
  string name_of_the_car;
  string color_of_the_car;
  string plate_number;
  vector<string> car_types;
  vector<string> car_colors;
public:
  Cars();
  string get_car();
};

#endif
