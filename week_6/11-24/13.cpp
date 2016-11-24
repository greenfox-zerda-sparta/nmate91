#include <iostream>
#include <string>
#include <vector>

using namespace std;

void create_2_dim_basic_mtx(vector< vector<int> >& grid);
void extend_2_dim_basic_mtx(vector< vector<int> >& grid);
void mirror_hor(vector< vector<int> >& grid);
void mirror_ver(vector< vector<int> >& grid);

int main() {
	//Create a 2 dimensional vector with matrix!
	    // 1 0 0 0
    	// 0 1 0 0
    	// 0 0 1 0
    	// 0 0 0 1
	// Extend it to the following format:
	    // 1 1 1 1 1
    	// 0 1 0 0 1
    	// 0 0 1 0 1
    	// 0 0 0 1 1
	    // 0 0 0 0 1
	// Mirror it horizontaly!
	// Mirror it verticaly!
  vector< vector<int> > victor(4, vector<int>(4, 0));
  create_2_dim_basic_mtx(victor);
  cout << endl;
  extend_2_dim_basic_mtx(victor);
  cout << endl;
  mirror_hor(victor);
  cout << endl;
  mirror_ver(victor);
  return 0;
}

void create_2_dim_basic_mtx(vector< vector<int> >& grid) {
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      if (row == col) {
        grid[row][col] = 1;
      }
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
}

void extend_2_dim_basic_mtx(vector< vector<int> >& grid) {
  for (int row = 0; row < grid.size(); row++) {
    grid[row].push_back(1);
  }
  vector<int>victor_vector_1(5, 0);
  grid.push_back(victor_vector_1);
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      if (row == 0 || (row == 4 && col == 4)) {
        grid[row][col] = 1;
      }
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
}

void mirror_hor(vector< vector<int> >& grid) {
  for (int row = 0; row < grid.size() / 2; row++) {
    swap(grid[row], grid[grid.size() - 1 - row]);
  }
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      cout << grid[row][col] << " ";
    }
    cout << endl;
   }
}

void mirror_ver(vector< vector<int> >& grid) {
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size() / 2; col++) {
      swap(grid[row][col], grid[row][grid.size() - 1 - col]);
    }
  }
  for (int row = 0; row < grid.size(); row++) {
    for (int col = 0; col < grid[row].size(); col++) {
      cout << grid[row][col] << " ";
    }
    cout << endl;
  }
}
