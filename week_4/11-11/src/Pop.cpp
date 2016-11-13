#include "Pop.h"
#include <iostream>
#include <string>
using namespace std;


Pop::Pop(string _artist, string _title) : Song() {
  this->artist = _artist;
  this->title = _title;
  this->genre = "Pop";
}
