#include "Cars.hpp"

Cars::Cars() {
  car_types =  {"Moszkvics", "Volga", "ZISZ", "Tatra", "Zbrojovka", "Hotchkiss", "DAF", "Warszawa", "Puli", "Balaton", "Benz", "Marauder", "Zsiguli" , "IFA", "Fjord", "Trabant", "Wartburg", "Martini" };
  car_colors = { "Piros", "Narancssárga", "Zöld", "Kék", "Türkiz", "Barna", "Lila", "Sárga", "Fekete", "Fehér" };
  name_of_the_car = car_types[rand() % 18];
  color_of_the_car = car_colors[rand() % 10];
  char plate_number[7];
  plate_number[0] = 'A';
  plate_number[1] = 'A' + rand() % 26;
  plate_number[2] = 'A' + rand() % 26;
  plate_number[3] = '-';
  plate_number[4] = '0' + rand() % 9;
  plate_number[5] = '0' + rand() % 9;
  plate_number[6] = '0' + rand() % 9;
}

void Cars::print_car() {
  cout << name_of_the_car << endl;
  cout << color_of_the_car << endl;
  for (int i = 0; i < 7; i++) {
    cout << plate_number[i];
  }
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
