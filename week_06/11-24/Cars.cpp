#include "Cars.hpp"

Cars::Cars() {
  car_types =  {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini" };
  car_colors = { "Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér" };
  name_of_the_car = car_types[rand() % 18];
  color_of_the_car = car_colors[rand() % 10];
  string plate_number = "A";
  plate_number.insert(plate_number.end(), ('A' + rand() % 26));
  plate_number.insert(plate_number.end(), ('A' + rand() % 26));
  plate_number.insert(plate_number.end(), ('-'));
  plate_number.insert(plate_number.end(), ('0' + rand() % 9));
  plate_number.insert(plate_number.end(), ('0' + rand() % 9));
  plate_number.insert(plate_number.end(), ('0' + rand() % 9));
}

string Cars::get_car() {
  string result;
  result = name_of_the_car + "\n" + color_of_the_car + "\n" + plate_number + "\n";
  return result;
}
/*
vector<vector<vector<string> > > parking_lot (4, vector<vector<string> >(4, vector <string>(8)));
for (int i = 0; i < parking_lot.size(); i++){
for (int j = 0; j < parking_lot[i].size(); i++){
for (int k = 0; k < parking_lot[i][j].size(); i++){
parking_lot[i][j][k] =
}
}
}
*/
