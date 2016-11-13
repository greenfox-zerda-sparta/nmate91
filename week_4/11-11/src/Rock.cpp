#include "Rock.h"
#include <iostream>
#include <string>
using namespace std;


Rock::Rock(string _artist, string _title) : Song() {
  this->artist = _artist;
  this->title = _title;
  this->genre = "Rock";
}
