#include <string>
#include <iostream>

using namespace std;

struct Pirate {
  string name;
  bool has_wooden_leg;
  short int gold_count;
};

// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

int sum(Pirate array[6], int length){
  int summa;
  for (int i = 0; i < length; i++){
    summa += array[i].gold_count;
  }
  return summa;
}

float avg(Pirate array[6], int length){
  float summa, avg;
  for (int i = 0; i < length; i++){
    summa += array[i].gold_count;
  }
  avg = float (summa)/float(length);
  return avg;
}

void richest(Pirate array[6], int length) {
  int maxelement = 0;
  string richest_p;
  for (int i = 0; i < 6; i++) {
    if (array[i].gold_count > maxelement && array[i].has_wooden_leg == true){
      maxelement = array[i].gold_count;
      richest_p = array[i].name;
    }
}
  cout << richest_p << endl;
}

int main() {
  Pirate pirates[] = {
    {"Jack", false, 18},
    {"Uwe", true, 8},
    {"Hook", true, 12},
    {"Halloween kid", false, 0},
    {"Sea Wolf", true, 14},
    {"Morgan", false, 1}
  };
  int length = 6;
  cout << sum(pirates, length) << endl;
  cout << avg(pirates, length) << endl;
  richest(pirates, length);
  return 0;
}
