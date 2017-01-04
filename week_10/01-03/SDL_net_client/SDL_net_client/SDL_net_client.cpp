#include "stdafx.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>
#include "ClientSocket.h"
#include "./game_logic/game_engine_from_eggdice.hpp"
#include "./game_logic/my_game.hpp"

int main(int argc, char *argv[]) {
  MyGame game;
  GameEngine engine(&game, 380, 380);
  engine.run();
  return 0;
}

  /*if (SDLNet_Init() == -1) {
    std::cerr << "Failed to intialise SDL_net: " << SDLNet_GetError() << std::endl;
    exit(-1);
  }
  ClientSocket *cs;
  try {
    cs = new ClientSocket("127.0.0.1", 1234, 512);
  }
  catch (SocketException e) {
    std::cerr << "Something went wrong creating a ClientSocket object." << std::endl;
    std::cerr << "Error is: " << e.what() << std::endl;
    std::cerr << "Terminating application." << std::endl;
    exit(-1);
  }
  try {
    cs->connectToServer();
    string receivedMessage = "";
    cout << "Use /quit to disconnect or /shutdown to shutdown the server." << endl;
    cs->displayPrompt();
    do {
      receivedMessage = cs->checkForIncomingMessages();
      if (receivedMessage != "") {
        cs->displayMessage(receivedMessage);
        cs->displayPrompt();
      }
      cs->getUserInput();
    } 
    while ((cs->getShutdownStatus() == false));
  }
  catch (SocketException e) {
    cerr << "Caught an exception in the main loop..." << endl;
    cerr << e.what() << endl;
    cerr << "Terminating application." << endl;
  }
  SDLNet_Quit();
}*/