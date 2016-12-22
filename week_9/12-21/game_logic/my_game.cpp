#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
}

MyGame::~MyGame() {
  delete board;
}

void MyGame::init(GameContext& context) {
  
}

void MyGame::render(GameContext& context) {
  
}
