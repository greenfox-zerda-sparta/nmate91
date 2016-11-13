#include "JukeBox.h"

JukeBox::JukeBox() : songs() {
  this->count_songs = 0;
}

void JukeBox::add_song(Song& song) {
  songs.push_song(song);
}

void JukeBox::rate_song(Song& song, double value) {
  if (song.get_genre() == "Rock" && value <= 5 && value >= 2) {
    song.set_rating(value);
  }
  else if (song.get_genre() == "Pop" && value <= 5 && value >= 1) {
    song.set_rating(value);
  }
  else if (song.get_genre() == "Reggie" && value <= 4 && value >= 1) {
    song.set_rating(value);
  }
  return;
}
