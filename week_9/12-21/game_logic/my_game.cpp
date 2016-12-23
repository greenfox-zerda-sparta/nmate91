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
}

void MyGame::render(GameContext& context) {
  if (context.was_key_pressed(CLICK)) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    board->who_is_next(x/20, y/20);
    context.reset_keys();
  }
  if (board->is_won(PLAYER_1) || board->is_won(PLAYER_2)) {
    delete board;
    this->board = new Board;
  }
  board->draw_board(context);
  context.render(); 
}
