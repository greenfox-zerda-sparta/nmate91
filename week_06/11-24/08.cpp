#include <iostream>
#include <string>
#include <vector>

using namespace std;

void suvi_function (vector<char>& v, int input_index) throw(int);

int main() {
	//create a vector of characters with the size of 8
	//ask the user to fill this vector with characters one by one
	//at the end make sure the vector holds the letters of "GREENFOX"
	//so correct the user if he/she gives a different letter from the one we want them to give :)
  vector<char>green_fox_vector(8);
  int index = 0;
  suvi_function(green_fox_vector, index);
  return 0;
}

void suvi_function (vector<char>& v, int input_index) throw(int) {
  char my_char;
  char green_fox_array[8] = {'G', 'R', 'E', 'E', 'N', 'F', 'O', 'X'};
  try {
    for(int i = input_index; i < 8; i++) {
      cout << "Please give the " << i + 1 << "th char." << endl;
      cin >> my_char;
      if (my_char != green_fox_array[i]) {
        throw i;
      }
      v[i] = my_char;
    }
  }
  catch (int c_index) {
    cout << "Please write the letter " << green_fox_array[c_index] << "...or go home." << endl;
    return suvi_function(v, c_index);
  }
  cout << "Congrats, you've successfully written GREENFOX. GG BB WP." << endl;
}
