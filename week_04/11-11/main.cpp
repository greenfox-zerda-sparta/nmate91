#include <iostream>
#include <string>
#include "Rock.h"
#include "Pop.h"
#include "Reggie.h"
#include "JukeBox.h"
using namespace std;

int main () {
  JukeBox jukebox;
  cout << jukebox.get_top_genre() << endl;

  Rock painforpleasure = Rock("Sum 41", "Pain for pleasure");
  jukebox.add_song(painforpleasure);
  jukebox.rate_song(painforpleasure, 3);
  jukebox.rate_song(painforpleasure, 5);
  jukebox.rate_song(painforpleasure, 3);
  cout << painforpleasure.get_artist() << ": ";
  cout << painforpleasure.get_title() << "; Average rating: ";
  cout << painforpleasure.get_avg_song() << ", Genre: ";
  cout << painforpleasure.get_genre() << endl;

  Rock fatlip = Rock("Sum 41", "Fat Lip");
  jukebox.add_song(fatlip);
  jukebox.rate_song(fatlip, 5);
  jukebox.rate_song(fatlip, 5);
  jukebox.rate_song(fatlip, 5);
  cout << fatlip.get_artist() << ": ";
  cout << fatlip.get_title() << "; Average rating: ";
  cout << fatlip.get_avg_song() << ", Genre: ";
  cout << fatlip.get_genre() << endl;

  Pop hellof = Pop("Schoolboy Q", "Hell of a night");
  jukebox.add_song(hellof);
  jukebox.rate_song(hellof, 3);
  jukebox.rate_song(hellof, 4);
  jukebox.rate_song(hellof, 3);
  cout << hellof.get_artist() << ": ";
  cout << hellof.get_title() << "; Average rating: ";
  cout << hellof.get_avg_song() << ", Genre: ";
  cout << hellof.get_genre() << endl;

  Reggie badboyz = Reggie("Bob Marley", "Bad boys");
  jukebox.add_song(badboyz);
  jukebox.rate_song(badboyz, 3);
  jukebox.rate_song(badboyz, 1);
  jukebox.rate_song(badboyz, 3);
  cout << badboyz.get_artist() << ": ";
  cout << badboyz.get_title() << "; Average rating: ";
  cout << badboyz.get_avg_song() << ", Genre: ";
  cout << badboyz.get_genre() << endl;

  cout << "Sum 41 rating: " << jukebox.get_artist_rating("Sum 41") << endl;
  cout << "Pop rating: " << jukebox.get_genre_rating("Pop") << endl;
  cout << "Top title: " << jukebox.get_top_title() << endl;
  cout << "Top genre: " << jukebox.get_top_genre() << endl;
}
