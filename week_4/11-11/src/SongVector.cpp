#include "SongVector.h"
// what does this shit
SongVector::SongVector() {
  songs = NULL;
  song_count = 0;
}

SongVector::~SongVector() {
  if (songs != NULL) {
    delete[] songs;
    songs = NULL;
  }
}

void SongVector::push_song(Song& song) {
  Song** temp = new Song*[song_count + 1];
  if (songs != NULL) {
    for (int i = 0; i < song_count; ++i) {
      temp[i] = songs[i];
    }
  }
  temp[song_count] = &song;
  delete[] songs;
  songs = temp;
  ++song_count;
}
