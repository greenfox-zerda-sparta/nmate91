#ifndef ROCK_H
#define ROCK_H
#include "Song.h"
#include <iostream>
using namespace std;

class Rock : public Song {
public:
  Rock(string _artist, string _title);
};

#endif // ROCK_H
