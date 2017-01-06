#include <iostream>
#include <string>
#include <vector>

using namespace std;

void suvi_function(vector< vector<int> >& victor, int index_row, int index_col) throw (int);

int main() {
	//create a vector of vector of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vector
	//create a function which increase a specific element of an inner vector by 1
  vector< vector<int> > grid(5, vector<int>(5, 10));
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      grid[row][col] = 0;
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
  cout << endl;
  try {
    suvi_function(grid, 5, 4);
  }
  catch(int something) {
    cerr << "What the fuck dude" << endl;
  }
  return 0;
}

void suvi_function(vector< vector<int> >& victor, int index_row, int index_col) throw (int) {
  cout << victor.size() << endl << endl;
  if (victor.size() < index_row + 1 || victor.size() < index_col + 1 || index_row < 0 || index_col < 0) {
    throw 1;
  }
  victor[index_row][index_col] = victor[index_row][index_col] + 1;
  for (int row = 0; row < victor.size(); row++) {
    for (int col = 0; col < victor[row].size(); col++) {
      cout << victor[row][col] << " ";
    }
  cout << endl;
  }
}
