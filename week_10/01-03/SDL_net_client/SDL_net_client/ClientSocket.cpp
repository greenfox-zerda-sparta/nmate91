#include "stdafx.h"
#include "ClientSocket.h"

const std::string ClientSocket::NAME = "Nyehh";
const unsigned int ClientSocket::CONNECTION_TIMEOUT_PERIOD = 5000;       
const unsigned int ClientSocket::SOCKET_SET_POLL_PERIOD = 10;       

ClientSocket::ClientSocket(string theServerAddress, unsigned int theServerPort, unsigned int theBufferSize) {
	serverHostname = theServerAddress;

	serverPort = theServerPort;
	bufferSize = theBufferSize;
	userInput = "";
	inputLength = 0;

	pBuffer = new char[bufferSize];

	socketSet = SDLNet_AllocSocketSet(2);
}

ClientSocket::~ClientSocket() {
	SDLNet_TCP_Close(serverSocket);
	SDLNet_TCP_Close(clientSocket);

	SDLNet_FreeSocketSet(socketSet);

	delete pBuffer;
}

void ClientSocket::connectToServer() {
	int hostResolved = SDLNet_ResolveHost(&serverIP, serverHostname.c_str(), serverPort);

	clientSocket = SDLNet_TCP_Open(&serverIP);
	SDLNet_TCP_AddSocket(socketSet, clientSocket);

	int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::CONNECTION_TIMEOUT_PERIOD);

	int gotServerResponse = SDLNet_SocketReady(clientSocket);
	int serverResponseByteCount = SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);

	string bufferContents = pBuffer;
}

string ClientSocket::checkForIncomingMessages() {
	string receivedMessage = "";

	int activeSockets = SDLNet_CheckSockets(socketSet, ClientSocket::SOCKET_SET_POLL_PERIOD);

	if (activeSockets != 0) {
		int gotMessage = SDLNet_SocketReady(clientSocket);

		if (gotMessage != 0) {
			int serverResponseByteCount = SDLNet_TCP_Recv(clientSocket, pBuffer, bufferSize);

			if (serverResponseByteCount != 0) {
				receivedMessage = toString(pBuffer);
			}
		}
	}
	return receivedMessage;
}

void ClientSocket::displayMessage(string &receivedMessage) {
	cout << receivedMessage << endl;
	receivedMessage = "";
}

void ClientSocket::displayPrompt() {
	cout << userInput;
	fflush(stdout);
}

void ClientSocket::getUserInput() {
	int status = _kbhit();

	if (status != 0) {
		char theChar = _getch();
		cout << theChar;
		fflush(stdout);

		if ((int)theChar != 13) {
			userInput += theChar;
		}
		else {
			if (0 < userInput.size()) {
				strcpy_s(pBuffer, 512, userInput.c_str());
				inputLength = strlen(pBuffer) + 1;

				SDLNet_TCP_Send(clientSocket, (void *)pBuffer, inputLength);

				cout << endl;
				fflush(stdout);
				userInput = "";
			} 
		}
	} 
}