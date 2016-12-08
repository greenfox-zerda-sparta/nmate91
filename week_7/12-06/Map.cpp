#include "Map.h"
#include <time.h>

Map::Map() {
  srand(time(NULL));
  std::vector<std::vector<int>> new_v(10, std::vector<int>(10, 1));
  this->v = new_v;
  int random_number = 0;
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[i].size() - 1; j++) {
      random_number = rand() % 2;
      v[i][j] = random_number;
    }
  }
  for (int i = 1; i < v.size() - 1; i++) {
    for (int j = 1; j < v[i].size() - 1; j++) {
      if (v[i - 1][j - 1] == 0) {
        v[i][j] = 1;
      }
      else if (v[i][j - 1] == 1 && v[i - 1][j] == 1 && v[i][j + 1] == 1) {
        v[i][j] = 0;
      }
      else if (v[i][j - 1] == 0 && v[i + 1][j] == 0 && v[i - 1][j] == 0 && v[i][j + 1] == 0) {
        v[i][j] = 0;
      }
      else if ((v[i][j - 1] == 1 && v[i + 1][j] == 1) || (v[i - 1][j] == 1 && v[i][j + 1] == 1)) {
        v[i][j] = 1;
      }
    }
  }
}

Map::~Map() {
}