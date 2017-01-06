#pragma once
#include "./game_logic/game_engine_from_eggdice.hpp"

class ClientNetwork {
private:
  TCPsocket client;
  SDLNet_SocketSet set;
  int array_to_send_coordinates[100];
  int array_to_allocate_coordinates[2];
  const int* client_coordinates;
public:
	ClientNetwork();
	~ClientNetwork();
  bool is_receiving_data_from_client();
  int get_received_x_coordinate();
  int get_received_y_coordinate();
  void send_coordinates_to_server(int, int);
};

