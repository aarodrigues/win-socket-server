#pragma once
#include <iostream>
#include <stdlib.h>

#include <nlohmann/json.hpp>



class ParseCommand
{
public:
	ParseCommand();
	~ParseCommand();
	char str_command[256];
	std::string executeCommand();
	void readCommand();
	void readConfigJson(std::string fileName);
	std::string replyTest(std::string str);
	void editConfigFile();
	std::string showCommands();
	void createCommandMap();

private:

	nlohmann::json jsonFile;
	template<typename T> 
	std::map<std::string, T > map_command(std::string K, T &value) {
		std::map<std::string, T> map;
		map[K] = value;
		return map;
	}

};

