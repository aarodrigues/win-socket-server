#include "stdafx.h"
#include "ParseCommand.h"

#include <fstream>
#include <memory>
#include <vector>
#include <iostream>
#include <cstring>

using json = nlohmann::json;

const char *edit_json_config = "edit-config";
const char *command_help = "help";

ParseCommand::ParseCommand()
{

}

ParseCommand::~ParseCommand()
{

}

std::string ParseCommand::executeCommand() {
	
	readCommand();
	//used to find the string into json file
	//std::string result = jsonFile.find(this->str_command) != jsonFile.end() ? jsonFile.find(this->str_command).key() : this->str_command;
	if (strcmp(this->str_command, command_help) == 0)
		return showCommands();
	else
		return std::string(this->str_command);
	/*if (strcmp(this->str_command, edit_json_config) == 0)
		editConfigFile();
	else
		system(this->str_command);*/
	std::vector<std::string> returnRandom = { "fail","sucess","not found","wierd","crash" };
	int idx = rand() % 4;

	return replyTest(returnRandom[idx]);
}

void ParseCommand::editConfigFile() {
	std::cout << "Here gonna edit the config file" << std::endl;
}

void ParseCommand::readCommand() {

		readConfigJson("../SocketServer/config/commands_description.json");
}


void ParseCommand::readConfigJson(std::string fileName) {
	//std::ifstream file("hySpex_transcript.json");
	std::ifstream file(fileName);
	json jsonFile;
	if (file.is_open())
	{
		file >> this->jsonFile;
	}
	else {
		std::cout << "Unable to open json file!" << std::endl;
	}
	
}

std::string ParseCommand::showCommands() {
	std::string list;
	for (json::iterator it = jsonFile.begin(); it != jsonFile.end(); ++it) {
		list += it.key() + " - " + it.value().get<std::string>() + "\n"; 
	}
	std::cout << list << std::endl;
	return list;
}


std::string ParseCommand::replyTest(std::string str) {
	json jsonFile;
	std::ifstream file("test.json");
	if (file.is_open())
	{	
		file >> jsonFile;
	}
	else {
		return std::string("Unable to open the file!\n");
	}

	return jsonFile[str];
}


void ParseCommand::createCommandMap() {
	//map_command("help", this->showCommands);
}
