#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <string>
#include <sys/types.h>
#include <stdlib.h>

#include <WS2tcpip.h>
#include <WinSock2.h>
#include "ParseCommand.h"

class Server
{
public:
	Server(const int port, const int connections);
	~Server();
	void startWinSocket();
	int initSocket();
	void sendData(std::string str);
	void receiveData();
	void listenSocket();
	int acceptConnection();
	void connectionManager();

private:
	SOCKET server;
	int port;
	int connection_numbers;
	int my_socket;
	int clientCount;
	struct sockaddr_in server_address;
	socklen_t size;

	char buffer[256];
	int con_status;
	char bb;

	ParseCommand p_cmd;

};

