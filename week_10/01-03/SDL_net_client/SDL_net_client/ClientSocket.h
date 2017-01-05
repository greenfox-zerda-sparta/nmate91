#ifndef SOCKET_H
#define SOCKET_H

#include <conio.h>     
#include <iostream>
#include <string>
#include <sstream>   
#include "SDL_net.h"         

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class ClientSocket {
	private:

		unsigned int serverPort;
		unsigned int bufferSize;

		string serverHostname; 
		IPaddress serverIP;      
		TCPsocket serverSocket;     
		TCPsocket clientSocket;     

		char *pBuffer;        
		string userInput;        
		int inputLength;     

		SDLNet_SocketSet socketSet; 

	public:
		static const string NAME;
		static const unsigned int CONNECTION_TIMEOUT_PERIOD;
		static const unsigned int SOCKET_SET_POLL_PERIOD;

		ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize);
		~ClientSocket();

		void connectToServer();
		string checkForIncomingMessages();
		void displayMessage(string &receivedMessage);
		void displayPrompt();
		void getUserInput();
};

template<class T>
std::string toString(const T& t) {
	std::ostringstream stream;
	stream << t;
	return stream.str();
}

#endif
