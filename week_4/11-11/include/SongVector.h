#ifndef SONGVECTOR_H
#define SONGVECTOR_H
#include "Song.h"

class SongVector {
public:
  Song** songs;
  int song_count;
  SongVector();
  ~SongVector();
  void push_song(Song& song);
  string song_artist();
  double song_rating();
};

#endif // SONGVECTOR_H
