#pragma once

#include "SharedVariables.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

class SaveFileManager {
private:
	std::fstream file;
	std::string lineContent;
	std::string name;

public:
	bool exists;

public:
	SaveFileManager(const std::string& filename);
	~SaveFileManager();

public:
	void read();
	void write(int saveCode);

private:
	void associateValue(std::string value, std::string category);
};