#include "stdafx.h"
#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
  this->keycode = 0;
  this->player_1_counter = 0;
  this->player_2_counter = 0;

  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  //SDLNet_ResolveHost(&ip, "10.27.99.165", 1234);
  this->client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_Recv(client, text, 100);
  std::cout << text << std::endl;
  client_text = new int[2];
}

MyGame::~MyGame() {
  delete board;
  delete client_text;
  SDLNet_TCP_Close(client);
  SDL_Quit();
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
    
    array_coordinates[0] = x / 20;
    array_coordinates[1] = y / 20;
    client_text = array_coordinates;
    SDLNet_TCP_Send(client, client_text, 100);
    SDLNet_TCP_Recv(client, text, 100);
    x = text[0];
    y = text[1];
    board->who_is_next(x + 1, y + 1);

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
