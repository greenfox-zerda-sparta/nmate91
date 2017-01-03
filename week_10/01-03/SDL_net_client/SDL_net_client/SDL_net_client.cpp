#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "ClientSocket.h"

/*int main(int argc, char *args[]) {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  while (1) {
    char text[100];
    SDLNet_TCP_Recv(client, text, 100);
    std::cout << text;
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}*/

// SDL_net Client | r3dux.org | 14/01/2011

// Includes for non-blocking keyboard input
// Re-written simple SDL_net socket client example | Nov 2011 | r3dux
// Library dependencies: libSDL, libSDL_net

int main(int argc, char *argv[]) {
  // Initialise SDL_net (Note: We don't initialise or use normal SDL at all - only the SDL_net library!)
  if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }

  // Create a pointer to a ClientSocket object
  ClientSocket *cs;

  try {
    // Try to instantiate the client socket
    // Parameters: server address, port number, buffer size (i.e. max message size)
    // Note: You can provide the serverURL as a dot-quad ("1.2.3.4") or a hostname ("server.foo.com")
    cs = new ClientSocket("127.0.0.1", 1234, 512);
  }
  catch (SocketException e) {
    std::cerr << "Something went wrong creating a ClientSocket object." << std::endl;
    std::cerr << "Error is: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }

  try {
    // Attempt to connect to the server at the provided address and port
    cs->connectToServer();

    string receivedMessage = "";

    cout << "Use /quit to disconnect or /shutdown to shutdown the server." << endl;

    // Display the initial prompt
    cs->displayPrompt();

    // Run the main loop...
    do {
      // Check if we've received a message
      receivedMessage = cs->checkForIncomingMessages();

      // If so then...
      if (receivedMessage != "") {
        // Display the message and then blank it...
        cs->displayMessage(receivedMessage);

        // ...and then re-display the prompt along with any typed-but-not-yet-sent input
        cs->displayPrompt();
      }

      // Get and deal with input from the user in a non-blocking manner
      cs->getUserInput();

      // ... until we decide to quit or the server is shut down
    } while ((cs->getShutdownStatus() == false));

  }
  catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << endl;
    cerr << e.what() << endl;
    cerr << "Terminating application." << endl;
  }

  // Shutdown SDLNet - our ClientSocket will clean up after itself on destruction
  SDLNet_Quit();

  return 0;
}