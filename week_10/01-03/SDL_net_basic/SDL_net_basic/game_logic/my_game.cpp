#include "stdafx.h"
#include "my_game.hpp"

MyGame::MyGame() {
  this->board = new Board;
  this->keycode = 0;
  this->player_1_counter = 0;
  this->player_2_counter = 0;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  SDLNet_ResolveHost(&ip, NULL, 1234);
  server = SDLNet_TCP_Open(&ip);
  client = SDLNet_TCP_Accept(server);
  text = "data_sent_for_client";
}

MyGame::~MyGame() {
  delete board;
  SDLNet_TCP_Close(server);
  SDL_Quit();
}

void MyGame::init(GameContext& context) {
  context.load_file("0.bmp");
  context.load_file("1.bmp"); 
  context.load_file("2.bmp");
}

void MyGame::render(GameContext& context) {
  char client_text[100];
  if (client) {
    SDLNet_TCP_Recv(client, client_text, 100);
    std::cout << client_text;
  }
  if (context.was_key_pressed(CLICK)) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    board->who_is_next(x/20, y/20);
    
    if (client) {
      SDLNet_TCP_Send(client, client_text, 100);
    }


    /*
    std::cout << text << std::endl;
    std::string input = "x: " + to_string(x/20) + "\n" + "y: " + to_string(y/20) + "\n" + "\n";
    client_text = input.c_str();
    SDLNet_TCP_Send(client, client_text, 100);
    */


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
