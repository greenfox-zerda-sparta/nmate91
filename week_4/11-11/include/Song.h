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
  string get_genre();
  string get_artist();
  string get_title();
  void set_rating(double _rating);
};

#endif // SONG_H
