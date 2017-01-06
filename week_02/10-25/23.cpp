#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//Create an array which is an 8x8 matrix. This is a checkers board. 'W' represents white checkers, 'B'
//represents black checkers. White squares are represented by '_', black squares are represented by '#'
//Create a function that moves a certain checker from a position to an other. Should be called: "move"
//Create a function that gives You back the possible positions the checker can go to. Should be called: "possibleSteps"
//Create a function that takes down an other checker by letting the one jumping over the other. Should be called: "take"
//All checkers are represented by their indices.
//Print out the whole board. Make some moves and illustrate them by printing out the whole board again.
//Create a function to do so. it should be called "printBoard"

void draw(string array[8][8]){
  int i,j;
  cout << "Hi! This is a Checkers game, the row and the column numbers are from 0 to 7." << endl;
  for (i = 0; i <= 7; i++) {
    for (j = 0; j < 1; j++) {
      if (i % 2 == 0) {
        array[i][j] = '_';
      }
      else {
        array[i][j] = 'W';
      }
    }
    for (j = 1; j < 2; j++) {
      if (i % 2 == 1) {
        array[i][j] = '_';
      }
      else {
        array[i][j] = 'W';
      }
    }
    for (j = 2; j < 3; j++){
      if (i % 2 == 0) {
          array[i][j] = '_';
        }
        else {
          array[i][j] = 'W';
        }
      }
    for (j = 3; j < 4; j++){
        if (i % 2 == 1) {
            array[i][j] = '_';
          }
          else {
            array[i][j] = '#';
          }
        }
    for (j = 4; j < 5; j++) {
      if (i % 2 == 1) {
        array[i][j] = '#';
      }
      else {
        array[i][j] = '_';
      }
    }
    for (j = 5; j < 6; j++) {
      if (i % 2 == 0) {
        array[i][j] = 'B';
      }
      else {
        array[i][j] = '_';
      }
    }
    for (j = 6; j < 7; j++) {
      if (i % 2 == 0) {
        array[i][j] = '_';
      }
      else {
        array[i][j] = 'B';
    }
  }
    for (j = 7; j <= 7; j++){
      if (i % 2 == 0) {
              array[i][j] = 'B';
            }
            else {
              array[i][j] = '_';
            }
    }
  }
  for (i = 0; i <= 7; i++) {
    cout << endl;
    for (j = 0; j <= 7; j++) {
      cout << array[i][j] << ' ';
    }
  }
  cout << endl;
}

void move(string array[8][8]) {
  int i,j,k,l;
  cout << "From which row?" << endl;
  cin >> i;
  cout << "From which column?" << endl;
  cin >> j;
  cout << "Where? Row." << endl;
  cin >> k;
  cout << "Where? Column." << endl;
  cin >> l;
  if ((abs(i-k) == 1) && (abs(j-l) == 1) && (array[i][j] == "W" || "B") && (array[k][l] == "#" || "B" || "W")) {
    if (array [k][l] == "W" || "B"){
      array[k][l] = "#";
    }
    swap(array[i][j], array[k][l]);
  } else {
    cout << "Invailid move. Try again." << endl;
    move(array);
  }
}

int main(int argv, char** argc) {
  string array[8][8], yesorno;
  draw(array);
  cout << endl;
  for (;;){
    cout << "You want a move? (y/n)" << endl;
    cin >> yesorno;
    if (yesorno == "y") {
      move(array);
      for (int i = 0; i <= 7; i++) {
        cout << endl;
        for (int j = 0; j <= 7; j++) {
          cout << array[i][j] << ' ';
        }
      }
    } else {
      break;
    }
  }
  cin.get();
  return 0;
}
