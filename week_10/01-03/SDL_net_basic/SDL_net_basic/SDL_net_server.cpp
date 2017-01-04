#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "./game_logic/game_engine_from_eggdice.hpp"
#include "./game_logic/my_game.hpp"
/*
int main(int argc, char *argv[]) {
  MyGame game;
  GameEngine engine(&game, 380, 380);
  engine.run();
  return 0;
}}*/



int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  const char* text = "data_sent_for_client";
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      SDLNet_TCP_Send(client, text, 100);
      char client_text[100];
      while (client_text[0] != 'q') {
        SDLNet_TCP_Recv(client, client_text, 100);
        std::cout << client_text;
        SDLNet_TCP_Send(client, client_text, 100);
      }
      SDLNet_TCP_Close(client);
      break;
    }
  }
  SDLNet_TCP_Close(server);
  SDL_Quit();
  return 0;
}