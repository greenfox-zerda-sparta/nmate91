#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
  this->keycode = 0;
}

MyGame::~MyGame() {
  delete board;
}

void MyGame::init(GameContext& context) {
  context.load_file("0.bmp");
  context.load_file("1.bmp"); 
  context.load_file("2.bmp");
  context.load_file("z.bmp"); 
}

void MyGame::render(GameContext& context) {
  if (context.was_key_pressed(CLICK)) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    board->who_is_next(x/20, y/20);
    context.reset_keys();
  }
  if (board->is_won(PLAYER_1) || board->is_won(PLAYER_2)) {
    context.draw_sprite_big("z.bmp", 0, 0);
  }
  else {
    draw_board(context);
  }
  context.render();
}

void MyGame::draw_board(GameContext& context) {
  for (int i = 0; i < board->get_vector().size(); i++) {
    for (int j = 0; j < board->get_vector().size(); j++) {
      if (board->get_vector()[i][j] == EMPTY) {
        context.draw_sprite("0.bmp", i * 20, j * 20);
      }
      else if (board->get_vector()[i][j] == PLAYER_1) {
        context.draw_sprite("1.bmp", i * 20, j * 20);
      }
      else if (board->get_vector()[i][j] == PLAYER_2) {
        context.draw_sprite("2.bmp", i* 20, j *20);
      }
    }
  }
}
