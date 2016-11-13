#include <iostream>
#include <string>
#include "Song.h"
#include "Rock.h"
#include "Pop.h"
#include "Reggie.h"
using namespace std;

int main () {
  Rock painforpleasure = Rock("Sum 41", "Pain for pleasure");
  painforpleasure.set_rating(5);
  painforpleasure.set_rating(2);
  painforpleasure.set_rating(3);
  painforpleasure.set_rating(5);
  cout << painforpleasure.get_artist() << endl;
  cout << painforpleasure.get_title() << endl;
  cout << painforpleasure.get_avg_song() << endl;
  cout << painforpleasure.get_genre() << endl;

  Pop hellof = Pop("Schoolboy Q", "Hell of a night");
  hellof.set_rating(3);
  hellof.set_rating(4);
  hellof.set_rating(5);
  hellof.set_rating(1);
  cout << hellof.get_artist() << endl;
  cout << hellof.get_title() << endl;
  cout << hellof.get_avg_song() << endl;
  cout << hellof.get_genre() << endl;

  Reggie badboyz = Reggie("Bob Marley", "Bad boys");
  badboyz.set_rating(4);
  badboyz.set_rating(3);
  badboyz.set_rating(4);
  badboyz.set_rating(1);
  cout << badboyz.get_artist() << endl;
  cout << badboyz.get_title() << endl;
  cout << badboyz.get_avg_song() << endl;
  cout << badboyz.get_genre() << endl;
}
