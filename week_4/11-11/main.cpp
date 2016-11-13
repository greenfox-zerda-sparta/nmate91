#include <iostream>
#include <string>
#include "Song.h"
#include "Rock.h"
#include "Pop.h"
#include "Reggie.h"
#include "JukeBox.h"
using namespace std;

int main () {
  JukeBox jukebox;
  Rock painforpleasure = Rock("Sum 41", "Pain for pleasure");
  jukebox.add_song(painforpleasure);
  jukebox.rate_song(painforpleasure, 3);
  jukebox.rate_song(painforpleasure, 5);
  jukebox.rate_song(painforpleasure, 3);
  cout << painforpleasure.get_artist() << endl;
  cout << painforpleasure.get_title() << endl;
  cout << painforpleasure.get_avg_song() << endl;
  cout << painforpleasure.get_genre() << endl;

  Pop hellof = Pop("Schoolboy Q", "Hell of a night");
  jukebox.add_song(hellof);
  jukebox.rate_song(hellof, 3);
  jukebox.rate_song(hellof, 4);
  jukebox.rate_song(hellof, 3);
  cout << hellof.get_artist() << endl;
  cout << hellof.get_title() << endl;
  cout << hellof.get_avg_song() << endl;
  cout << hellof.get_genre() << endl;

  Reggie badboyz = Reggie("Bob Marley", "Bad boys");
  jukebox.add_song(badboyz);
  jukebox.rate_song(badboyz, 3);
  jukebox.rate_song(badboyz, 1);
  jukebox.rate_song(badboyz, 3);
  cout << badboyz.get_artist() << endl;
  cout << badboyz.get_title() << endl;
  cout << badboyz.get_avg_song() << endl;
  cout << badboyz.get_genre() << endl;
}
