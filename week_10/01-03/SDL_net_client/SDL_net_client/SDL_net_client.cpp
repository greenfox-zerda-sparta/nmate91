#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char *args[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  char text[100];
  SDLNet_TCP_Recv(client, text, sizeof(text));
  std::cout << text;
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}