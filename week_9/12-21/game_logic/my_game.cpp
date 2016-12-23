#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
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
  board->draw_board(context);
  context.render(); 
}
