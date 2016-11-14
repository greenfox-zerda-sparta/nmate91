#include "JukeBox.h"

JukeBox::JukeBox() : songs() {
  this->count_songs = 0;
}

void JukeBox::add_song(Song& song) {
  songs.push_song(song);
  this->song_id++;
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

double JukeBox::get_artist_rating(string _artist) {
  double artist_rate;
  int count_artist = 0;
  for (int i = 0; i < songs.song_count; i++) {
    if (songs.songs[i]->get_artist() == _artist) {
       artist_rate = artist_rate + songs.songs[i]->get_avg_song();
       count_artist++;
    }
  }
  return (artist_rate / count_artist);
}
