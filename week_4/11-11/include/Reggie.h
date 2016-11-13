#ifndef REGGIE_H
#define REGGIE_H
#include "Song.h"
#include <iostream>
using namespace std;

class Reggie : public Song {
public:
  Reggie(string _artist, string _title);
};

#endif
// REGGIE_H
