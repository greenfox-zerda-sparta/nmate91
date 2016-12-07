#include "MyGame.h"
#include <time.h>

MyGame::MyGame() {
  srand(time(NULL));
  std::vector<std::vector<int>> vic(10, std::vector<int>(10, 1));
  this->v = vic;
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

MyGame::~MyGame() {
}

void MyGame::init(GameContext& context) {
  context.load_file("floor.bmp");
  context.load_file("wall.bmp");
  context.load_file("hero-down.bmp");
  context.load_file("hero-up.bmp");
  context.load_file("hero-left.bmp");
  context.load_file("hero-right.bmp");
  context.load_file("skeleton.bmp");
  context.load_file("boss.bmp");
}

void MyGame::draw_player_direction(GameContext& context, int keycode) {
  switch (keycode) {
  case 0:
    context.draw_sprite("hero-up.bmp", x_player, y_player);
    break;
  case 1:
    context.draw_sprite("hero-right.bmp", x_player, y_player);
    break;
  case 2:
    context.draw_sprite("hero-down.bmp", x_player, y_player);
    break;
  case 3:
    context.draw_sprite("hero-left.bmp", x_player, y_player);
    break;
  }
}

void MyGame::draw_skeleton(GameContext& context) {
  int ske_counter = 0;
  for (int i = 5; i < v.size(); i++) {
    for (int j = 5; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton1 = j * 72;
        y_skeleton1 = i * 72;
        goto end1;
      }
    }
  }
  end1:
  for (int i = 6; i < v.size(); i++) {
    for (int j = 6; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton2 = i * 72;
        y_skeleton2 = j * 72;
        goto end2;
      }
    }
  }
  end2:
  for (int i = 7; i < v.size(); i++) {
    for (int j = 7; j < v[i].size(); j++) {
      if (v[i][j] == 1) {
        x_skeleton3 = i * 72;
        y_skeleton3 = j * 72;
        goto end3;
      }
    }
  }
  end3:
  context.draw_sprite("skeleton.bmp", x_skeleton1, y_skeleton1);
  context.draw_sprite("skeleton.bmp", x_skeleton2, y_skeleton2);
  context.draw_sprite("skeleton.bmp", x_skeleton3, y_skeleton3);
  context.draw_sprite("boss.bmp", x_boss, y_boss);
}

void MyGame::draw_map(GameContext& context) {
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

void MyGame::render(GameContext& context) {
  draw_map(context);
  draw_player_direction(context, keycode);
  draw_skeleton(context);
  if (context.was_key_pressed(ARROW_DOWN)) {
    y_player = y_player + 72;
    if (y_player > (720 - 72)) {
      y_player = (720 - 72);
    }
    else if (v[x_player / 72][y_player / 72] == 0) {
      y_player = y_player - 72;
    }
    keycode = 2;
  }
  else if (context.was_key_pressed(ARROW_UP)) {
    y_player = y_player - 72;
    if (y_player < 0) {
      y_player = 0;
    }
    else if (v[x_player / 72][y_player / 72] == 0) {
      y_player = y_player + 72;
    }
    keycode = 0;
  }
  else if (context.was_key_pressed(ARROW_LEFT)) {
    x_player = x_player - 72;
    if (x_player < 0) {
      x_player = 0;
    }
    else if (v[x_player / 72][y_player / 72] == 0) {
      x_player = x_player + 72;
    }
    keycode = 3;
  }
  else if (context.was_key_pressed(ARROW_RIGHT)) {
    x_player = x_player + 72;
    if (x_player >(720 - 72)) {
      x_player = (720 - 72);
    }
    else if (v[x_player / 72][y_player / 72] == 0) {
      x_player = x_player - 72;
    }
    keycode = 1;
  }
  context.render();
}