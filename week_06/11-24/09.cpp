#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
//create a vector of vector of integers, yeah a vector that holds vectors of integers
//the inner vectors have 5 integers, all of them 0
//the outer vector is holding 5 vector at the begining
//create a function that will add a new vector of integers to the end of our outer vector
  vector< vector<int> > grid(5, vector<int>(5, 0));
  int counter = 1;
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
  vector<int>victor(5, 9);
  grid.push_back(victor);
  cout << endl << endl;
  for (int row = 0; row < grid.size(); row++) {
   for (int col = 0; col < grid[row].size(); col++) {
     cout << grid[row][col] << " ";
     }
    cout << endl;
   }
  return 0;
}
