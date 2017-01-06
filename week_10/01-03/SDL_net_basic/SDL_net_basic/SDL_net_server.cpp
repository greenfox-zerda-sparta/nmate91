#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();

  std::vector<TCPsocket> clientvector;
  int client_count = 0;

  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  int* text = new int[2];
  SDLNet_SocketSet set = SDLNet_AllocSocketSet(3);
  while (1) {
  begin:
    client = SDLNet_TCP_Accept(server);
    if (client) {
      clientvector.push_back(client);
      SDLNet_TCP_AddSocket(set, clientvector[client_count]);
      client_count++;
      std::cout << "client connected" << client_count << std::endl;
      if (client_count != 2) {
        goto begin;
      }
    }
    if (clientvector.size() == 2) {
      SDLNet_TCP_Send(client, text, 100);
      std::cout << "Connection estabilished." << std::endl;
      int client_text[100];
      while (client_text[0] != 'q') {
        int activeSockets = SDLNet_CheckSockets(set, 10);
        if (activeSockets != 0) {
          int gotServerResponse = SDLNet_SocketReady(clientvector[1]);
          if (gotServerResponse != 0) {
            SDLNet_TCP_Recv(clientvector[1], client_text, 100);
            std::cout << client_text[0] << ", " << client_text[1] << std::endl;
            SDLNet_TCP_Send(clientvector[0], client_text, 100);
          }
          gotServerResponse = SDLNet_SocketReady(clientvector[0]);
          if (gotServerResponse != 0) {
            SDLNet_TCP_Recv(clientvector[0], client_text, 100);
            std::cout << client_text[0] << ", " << client_text[1] << std::endl;
            SDLNet_TCP_Send(clientvector[1], client_text, 100);
          }
        }
      }
      SDLNet_TCP_Close(clientvector[0]);
      SDLNet_TCP_Close(clientvector[1]);
      break;
    }
  }
  delete text;
  SDLNet_TCP_Close(server);
  SDL_Quit();
  return 0;
}