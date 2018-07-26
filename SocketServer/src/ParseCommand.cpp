#include "stdafx.h"
#include "ParseCommand.h"

#include <fstream>
#include <memory>
#include <vector>
#include <iostream>
#include <cstring>

using json = nlohmann::json;

ParseCommand::ParseCommand()
{

}

ParseCommand::~ParseCommand()
{

}

std::string ParseCommand::executeCommand() {
	system(this->str_command);
	std::vector<std::string> returnRandom = { "fail","sucess","not found","wierd","crash" };
	int idx = rand() % 4;

	//std::cout << " aiii ohhhh: " << returnRandom[idx] <<std::endl;
	//std::cout << "ai ta rolando: " << replyTest(returnRandom[idx]) << std::endl;
	return replyTest(returnRandom[idx]);
}

void ParseCommand::readCommand() {
	char str[256] = { 'ls' };
	if (strcpy_s(this->str_command, str))
		readConfigJson();
}


void ParseCommand::readConfigJson() {
	std::ifstream file("hySpex_transcript.json");
	json jsonFile;
	file >> jsonFile;


	for (json::iterator it = jsonFile.begin(); it != jsonFile.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
		if (it.key().compare(std::string(this->str_command)) == 0)
			std::cout << "ubsui subso subsoi: " << it.value() << std::endl;
	}
}


std::string ParseCommand::replyTest(std::string str) {
	std::ifstream file("test.json");
	json jsonFile;
	file >> jsonFile;

	return jsonFile[str];
	return std::string("teste");
}

