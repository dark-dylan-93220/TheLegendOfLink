#pragma once

#include "SharedVariables.h"
#include <iostream>
#include <fstream>
#include <string>

class SaveFileManager {
private:
	std::fstream file;
	std::string lineContent;
	std::string name;

public:
	SaveFileManager(const std::string& filename);
	~SaveFileManager();

public:
	void read();

private:
	void write(int saveCode);
	void associateValue(std::string value, std::string category);
};