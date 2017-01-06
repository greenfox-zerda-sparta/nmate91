#include "JukeBox.h"

JukeBox::JukeBox() : songs() {
  songs.songs = NULL;
}

void JukeBox::add_song(Song& song) {
  if (&song != NULL) {
    songs.push_song(song);
  }
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
  double artist_rate = 0;
  int count_artist = 0;
    for (int i = 0; i <  songs.song_count; i++) {
      if (songs.songs[i]->get_artist() == _artist) {
         artist_rate = artist_rate + songs.songs[i]->get_avg_song();
         count_artist++;
      }
    }
    return (artist_rate / count_artist);
}

double JukeBox::get_genre_rating(string _genre) {
  double genre_rate = 0;
  double count_genre = 0;
  for (int i = 0; i < songs.song_count; i++) {
    if (songs.songs[i]->get_genre() == _genre) {
       genre_rate = genre_rate + songs.songs[i]->get_avg_song();
       count_genre++;
    }
  }
  return (genre_rate / count_genre);
}

string JukeBox::get_top_title() {
  string top_title;
  double top_title_rate = 0;
  if (songs.songs != NULL) {
    for (int i = 0; i < songs.song_count; i++) {
      if (songs.songs[i]->get_avg_song() > top_title_rate) {
        top_title_rate = songs.songs[i]->get_avg_song();
        top_title = songs.songs[i]->get_title();
      }
    }
  }
  return top_title;
}

string JukeBox::get_top_genre() {
  if (songs.songs != NULL) {
    string top_genre = songs.songs[0]->get_genre();
    for (int i = 1; i < songs.song_count; i++) {
      if (get_genre_rating(songs.songs[i]->get_genre()) > get_genre_rating(top_genre)) {
        top_genre = songs.songs[i]->get_genre();
      }
      return top_genre;
    }
  }
  return "There are no songs stored in JukeBox.";
}
