#include <iostream>
#include <string>
#include <vector>

using namespace std;

void suvi_function(vector< vector<int> >& victor, int index) throw (int);

int main() {
	//create a vector of vector of integers
	//the inner vectors have 5 integers, all of them 0
	//the outer vector is holding 5 vector
	//create a function which increase the given inner vector elements by 1 (one inside vector, holding five 0)
  vector< vector<int> > grid(5, vector<int>(5, 0));
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
  try {
    suvi_function(grid, 2);
  }
  catch(int something) {
    cerr << "What the fuck dude" << endl;
  }
  return 0;
}

void suvi_function(vector< vector<int> >& victor, int index) throw (int) {
  if (victor.size() < index || index < 0) {
    throw 1;
  }
  for (int col = 0; col < victor[index].size(); col++) {
    victor[index][col] = victor[index][col] + 1;
  }
  cout << endl;
  for (int row = 0; row < victor.size(); row++) {
    for (int col = 0; col < victor[row].size(); col++) {
      cout << victor[row][col] << " ";
    }
  cout << endl;
  }
}
