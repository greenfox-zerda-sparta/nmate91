#include "stdafx.h"
#include "ClientNetwork.h"


ClientNetwork::ClientNetwork() {
	SDLNet_Init();
	IPaddress ip;
	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
	this->client = SDLNet_TCP_Open(&ip);
	SDLNet_TCP_Recv(client, array_to_send_coordinates, 100);
	std::cout << array_to_send_coordinates << std::endl;
  client_coordinates = new int[2];
  set = SDLNet_AllocSocketSet(3);
  SDLNet_TCP_AddSocket(set, client);
}

ClientNetwork::~ClientNetwork() {
  delete client_coordinates;
  SDLNet_FreeSocketSet(set);
  SDLNet_TCP_Close(client);
  SDL_Quit();
}

bool ClientNetwork::is_receiving_data_from_client() {
  if (SDLNet_CheckSockets(set, 100)) {
    if (SDLNet_SocketReady(client)) {
      return true;
    }
  }
  return false;
}

void ClientNetwork::send_coordinates_to_server(int x, int y) {
  array_to_allocate_coordinates[0] = x / 20;
  array_to_allocate_coordinates[1] = y / 20;
  client_coordinates = array_to_allocate_coordinates;
  SDLNet_TCP_Send(client, client_coordinates, 100);
}

int ClientNetwork::get_received_x_coordinate() {
  if (is_receiving_data_from_client()) {
    int msg = SDLNet_TCP_Recv(client, array_to_send_coordinates, 100);
    if (msg) {
      return array_to_send_coordinates[0];
    }
  }
}

int ClientNetwork::get_received_y_coordinate() {
  if (is_receiving_data_from_client()) {
    int msg = SDLNet_TCP_Recv(client, array_to_send_coordinates, 100);
    if (msg) {
      return array_to_send_coordinates[1];
    }
  }
}