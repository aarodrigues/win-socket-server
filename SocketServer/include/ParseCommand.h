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
	void readConfigJson();
	std::string replyTest(std::string str);

};

