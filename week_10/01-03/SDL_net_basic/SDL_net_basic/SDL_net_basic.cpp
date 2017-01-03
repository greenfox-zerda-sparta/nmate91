#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include <istream>

int main(int argc, char *args[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  std::string text;
  std::cout << "Write a message!" << std::endl;
  std::getline(std::cin, text);
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
      SDLNet_TCP_Close(client);
      break;
    }
  }
  SDL_Quit();
  return 0;
}
