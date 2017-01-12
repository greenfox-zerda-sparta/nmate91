#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();

  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  SDLNet_SocketSet set = SDLNet_AllocSocketSet(3);

  std::vector<TCPsocket> clientvector;
  int* integer_data = new int[2];
  int gotServerResponse;
  int activeSockets;      
  int client_data[100];
  int client_count = 0;

  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      clientvector.push_back(client);
      SDLNet_TCP_AddSocket(set, clientvector[client_count]);
      SDLNet_TCP_Send(client, integer_data, 100);
      client_count++;
    }
    if (clientvector.size() == 2) {
      std::cout << "Connection estabilished." << std::endl;
      while (client_data[0] != 'q') {
        activeSockets = SDLNet_CheckSockets(set, 10);
        if (activeSockets != 0) {
          gotServerResponse = SDLNet_SocketReady(clientvector[1]);
          if (gotServerResponse != 0) {
            SDLNet_TCP_Recv(clientvector[1], client_data, 100);
            std::cout << client_data[0] << ", " << client_data[1] << std::endl;
            SDLNet_TCP_Send(clientvector[0], client_data, 100);
          }
          gotServerResponse = SDLNet_SocketReady(clientvector[0]);
          if (gotServerResponse != 0) {
            SDLNet_TCP_Recv(clientvector[0], client_data, 100);
            std::cout << client_data[0] << ", " << client_data[1] << std::endl;
            SDLNet_TCP_Send(clientvector[1], client_data, 100);
          }
        }
      }
      SDLNet_TCP_Close(clientvector[0]);
      SDLNet_TCP_Close(clientvector[1]);
      break;
    }
  }
  delete integer_data;
  SDLNet_TCP_Close(server);
  SDL_Quit();
  return 0;
}