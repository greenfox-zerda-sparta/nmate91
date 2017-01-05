#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  int* text = new int[2];
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      SDLNet_TCP_Send(client, text, 100);
      std::cout << "Connection estabilished." << std::endl;
      int client_text[100];
      while (client_text[0] != 'q') {
        SDLNet_TCP_Recv(client, client_text, 100);
        std::cout << client_text[0] << std::endl;
        SDLNet_TCP_Send(client, client_text, 100);
      }
      SDLNet_TCP_Close(client);
      break;
    }
  }
  delete text;
  SDLNet_TCP_Close(server);
  SDL_Quit();
  return 0;
}