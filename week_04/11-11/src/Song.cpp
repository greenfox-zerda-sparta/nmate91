#include "Song.h"

Song::Song() {
  //constructor
}

Song::~Song() {

}

double Song::get_avg_song() {
  return (this->rating / this->count_rating);
}

string Song::get_artist() {
  return this->artist;
}

string Song::get_title() {
  return this->title;
}

 string Song::get_genre() {
  return this->genre;
}

void Song::set_rating(double _rating) {
  this->rating = this->rating + _rating;
  this->count_rating++;
}
