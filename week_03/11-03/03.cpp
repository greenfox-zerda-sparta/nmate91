#include <string>
#include <iostream>

using namespace std;

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  CarType type;
  double km;
  double gas;
};

void print_stats(Car& s) {
  if (s.type == TESLA){
    cout << s.type << "; " << s.km << endl;
  }
  else {
    cout << s.type << "; " << s.km << "; " << s.gas << endl;
  }
}

// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {
  Car my_car;
  my_car.type = TESLA;
  my_car.km = 12354;
  Car your_car;
  your_car.type = TOYOTA;
  your_car.km = 324324;
  your_car.gas = 1;
  print_stats(my_car);
  print_stats(your_car);
  return 0;
}
