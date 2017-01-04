#include "stdafx.h"
#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
  this->keycode = 0;
  this->player_1_counter = 0;
  this->player_2_counter = 0;
  if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }
  try {
    cs = new ClientSocket("127.0.0.1", 1234, 512);
  }
  catch (SocketException e) {
    std::cerr << "Something went wrong creating a ClientSocket object." << std::endl;
    std::cerr << "Error is: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }
  try {
    cs->connectToServer();
    cs->displayPrompt();
  }
  catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << endl;
    cerr << e.what() << endl;
    cerr << "Terminating application." << endl;
  }
}

MyGame::~MyGame() {
  delete board;
  SDLNet_Quit();
}

void MyGame::init(GameContext& context) {
  context.load_file("0.bmp");
  context.load_file("1.bmp"); 
  context.load_file("2.bmp");
}

void MyGame::render(GameContext& context) {

  //if(fogad adatot) { azokat hasznalja } else { getmousestate }

  if (context.was_key_pressed(CLICK)) {
    int x, y;

    SDL_GetMouseState(&x, &y);
    board->who_is_next(x/20, y/20);
    
    //ide kene, hogy kuldi az adatot

    context.reset_keys();
  }
  if (board->is_won(PLAYER_1)) {
    player_1_counter++; 
    std::cout << "PLAYER 1 won " << player_1_counter << " times." << std::endl;
    board->clear_board();
  }
  if (board->is_won(PLAYER_2)) {
    player_2_counter++;
    std::cout << "PLAYER 2 won " <<  player_2_counter << " times." <<  std::endl;
    board->clear_board();
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
