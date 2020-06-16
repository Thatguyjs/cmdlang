#pragma once

#include "../file/file.h"
#include "jump.h"

#include <vector>
#include <iostream>


class Interpreter {
private:

	// File info
	const char* _path = nullptr;
	std::string _data = "";
	unsigned long _dataLength = 0;

	unsigned long _index = 0;


	// Program info
	char* _cells = nullptr;
	unsigned _cellNum = 0;
	unsigned _cell = 0;

	std::vector<Jump> _jumps;
	unsigned _jumpNum = 0;


	// Error code
	int _error = 0;

public:

	Interpreter(const char* path);


	// Run the program
	int run();


	// Get the error message from an error code
	static const char* errorMessage(int code);

};