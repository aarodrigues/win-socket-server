#include "stdafx.h"
#include "Server.h"


Server::Server(const int port, const int connections)
{
	startWinSocket();
	this->server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server == INVALID_SOCKET) {
		std::string err = "Error creating socket: " + std::to_string(server);
		throw (err);
	}
	this->port = port;
	this->connection_numbers = connections;
}

Server::~Server()
{
}


void Server::startWinSocket() {
	WSAData wsaData;
	WORD dllVersion = MAKEWORD(2, 1);
	int startup = WSAStartup(dllVersion, &wsaData);
	if (startup != 0) {
		std::string err = "Error startup socket: " + std::to_string(startup);
		throw (err);
	}
}

int Server::initSocket() {

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);
	//server_address.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
	server_address.sin_port = htons(port);

	int binded = bind(this->server, (SOCKADDR*) &server_address, sizeof(server_address));
	if (binded == SOCKET_ERROR) {
		std::string err = "Error binding connection: " + std::to_string(binded);
		throw(err);
	}

	size = sizeof(server_address);
	return 0;
}

void Server::listenSocket() {
	listen(server, connection_numbers);
	std::cout << "Server started." << std::endl;
}

int Server::acceptConnection() {
	std::cout << "Waiting for connections ..." << std::endl;
	my_socket = accept(server, (struct sockaddr *) &server_address, &size);

	if (my_socket < 0) {
		std::string err = "Error on accepting: " + std::to_string(my_socket);
		throw(err);
	}

	strcpy_s(buffer, "=> Server connected...\n");
	send(my_socket, buffer, sizeof(buffer), 0);
	std::cout << "Client Connected." << std::endl;
	std::cout << "Waiting client request ..." << std::endl;

	return 0;
}

void Server::connectionManager() {
	acceptConnection();

	while (my_socket > 0) {
		receiveData();
	}

	closesocket(server);
}

void Server::sendData(std::string str) {
	std::cout << "Server: " + str << std::endl;
	std::string msg = str;
	send(my_socket, msg.c_str(), sizeof(buffer), 0);
}

void Server::receiveData() {
	std::cout << "Client: ";
	con_status = recv(my_socket, buffer, sizeof(buffer), 0);
	if (con_status == 0) {
		std::cout << "Connection lost!" << std::endl;
		acceptConnection();
	}
	//std::cout << "Nombre " << con_status <<std::endl;
	std::cout << buffer << std::endl;

	strcpy_s(this->p_cmd.str_command, buffer);
	//this->p_cmd.executeCommand2();
	sendData(this->p_cmd.executeCommand());
	
}
