// SocketServer.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

#include <iostream>
#include <string.h>
#include "Parsecommand.h"
#include "Server.h"
#include <fstream>
#include <memory>


int main()
{
	std::cout << "Hello Word" << std::endl;

	ParseCommand p_cmd;

	try {
		
		std::unique_ptr<Server>server_socket(new Server(1500, 1));
		server_socket->initSocket();
		server_socket->listenSocket();
		server_socket->connectionManager();

	}
	catch (std::string e) {
		std::cout << "Error: " << e << std::endl;
	}

	getchar();
    return 0;
}


