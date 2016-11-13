#include "Reggie.h"

#include <iostream>
#include <string>
using namespace std;


Reggie::Reggie(string _artist, string _title) : Song() {
  this->artist = _artist;
  this->title = _title;
  this->genre = "Reggie";
}
