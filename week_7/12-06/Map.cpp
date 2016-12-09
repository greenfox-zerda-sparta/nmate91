#include "Map.h"

Map::Map() {
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
      else if (v[i][j - 1] == 0 && v[i + 1][j] == 0 
        && v[i - 1][j] == 0 && v[i][j + 1] == 0) {
        v[i][j] = 0;
      }
      else if ((v[i][j - 1] == 1 && v[i + 1][j] == 1) 
        || (v[i - 1][j] == 1 && v[i][j + 1] == 1)) {
        v[i][j] = 1;
      }
    }
  }
}

Map::~Map() {
}

std::vector<std::vector<int>> Map::get_vector() {
  return v;
}

void Map::draw_map(GameContext& context) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      if (v[i][j] == 0) {
        context.draw_sprite("wall.bmp", i * 72, j * 72);
      }
      else if (v[i][j] == 1) {
        context.draw_sprite("floor.bmp", i * 72, j * 72);
      }
    }
  }
}

bool Map::is_floor(int x, int y) {
  if (v[x][y] == 1) {
    return true;
  }
  return false;
}

bool Map::is_monster(int x, int y) {
  if ((v[x][y] == 2) || (v[x][y] == 3)) {
    return true;
  }
  return false;
}

bool Map::is_monster_or_floor(int x, int y) {
  if ((v[x][y] == 1) || (v[x][y] == 2) || (v[x][y] == 3)) {
    return true;
  }
  return false;
}

void Map::set_map(int i, int j, int value) {
  v[i][j] = value;
}