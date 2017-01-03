#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

/*int main(int argc, char *args[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  SDLNet_SocketSet set;
  set = SDLNet_AllocSocketSet(16);
  int SDLNetTCPAddSocket(SDLNet_SocketSet, TCPsocket);
  int numused;
  numused = SDLNetTCPAddSocket(set, client);
  int numready; 
  numready = SDLNet_CheckSockets(set, 1000);
  while (1) {
    if (numready) {
      if (SDLNet_SocketReady(client)) {
        client = SDLNet_TCP_Accept(server);
        if (client) {
          std::string text;
          std::cout << "Write a message!" << std::endl;
          std::getline(std::cin, text);
          SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
          SDLNet_TCP_Close(client);
        } 
      }
    }
  }
  SDL_Quit();
  return 0;
}*/

// SDL_net Server | r3dux.org | 14/01/2011
// Re-written simple SDL_net socket client example | Nov 2011 | r3dux
// Library dependencies: libSDL, libSDL_net

#// Re-written simple SDL_net socket server example | Nov 2011 | r3dux
// Library dependencies: libSDL, libSDL_net

#include "ServerSocket.h"

int main(int argc, char *argv[]) {
  // Initialise SDL_net
  if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }

  // Create a pointer to a ServerSocket object
  ServerSocket *ss;

  try {
    // Try to instantiate the server socket
    // Parameters: port number, buffer size (i.e. max message size), max sockets
    ss = new ServerSocket(1234, 512, 3);
  }
  catch (SocketException e) {
    std::cerr << "Something went wrong creating a SocketServer object." << std::endl;
    std::cerr << "Error is: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }

  try {
    // Specify which client is active, -1 means "no client is active"
    int activeClient = -1;

    // Main loop...
    do {
      // Check for any incoming connections to the server socket
      ss->checkForConnections();

      // At least once, but as many times as necessary to process all active clients...
      do {
        // ...get the client number of any clients with unprocessed activity (returns -1 if none)
        activeClient = ss->checkForActivity();

        // If there's a client with unprocessed activity...
        if (activeClient != -1) {
          // ...then process that client!
          ss->dealWithActivity(activeClient);
        }

        // When there are no more clients with activity to process, continue...
      } while (activeClient != -1);

      // ...until we've been asked to shut down.
    } while (ss->getShutdownStatus() == false);

  }
  catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << endl;
    cerr << e.what() << endl;
    cerr << "Terminating application." << endl;
  }

  // Shutdown SDLNet - our ServerSocket will clean up after itself on destruction
  SDLNet_Quit();

  return 0;
}