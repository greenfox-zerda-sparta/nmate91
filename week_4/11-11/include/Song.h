#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;

class Song {
protected:
  string title = "";
  string artist = "";
  string genre = "";
  double rating = 0;
  double count_rating = 0;
public:
  Song();
  double get_avg_song();
  int get_avg_artist();
  int get_avg_genre();
  int get_top_song();
  string get_genre();
  void set_rating(double);
  string get_artist();
  string get_title();
};

#endif // SONG_H
