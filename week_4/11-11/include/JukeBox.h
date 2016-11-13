#ifndef JUKEBOX_H
#define JUKEBOX_H
#include "Song.h"
#include "SongVector.h"
#include "Rock.h"
#include "Pop.h"
#include "Reggie.h"

class JukeBox {
private:
  int count_songs;
  int song_id;
  SongVector songs;
public:
  JukeBox();
  void add_song(Song& song);
  void rate_song(Song& song, double value);
};

#endif // JUKEBOX_H
