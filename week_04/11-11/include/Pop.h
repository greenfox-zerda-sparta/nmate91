#ifndef POP_H
#define POP_H
#include "Song.h"
#include <iostream>
using namespace std;

class Pop : public Song {
public:
  Pop(string _artist, string _title);
};

#endif // ROCK_H
