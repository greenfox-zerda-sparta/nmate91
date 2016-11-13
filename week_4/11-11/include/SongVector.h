#ifndef SONGVECTOR_H
#define SONGVECTOR_H
#include "Song.h"

class SongVector {
private:
  Song** songs;
  int song_count;
public:
  SongVector();
  ~SongVector();
  void push_song(Song& song);
};

#endif // SONGVECTOR_H
