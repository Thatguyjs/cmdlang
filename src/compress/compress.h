#pragma once

#include "../file/file.h"
#include "jumpattr.h"

#include <vector>
#include <iostream>


class Compress {
private:

	// File info
	const char* _path = nullptr;
	std::string _data = "";
	unsigned long _dataLength = 0;

	unsigned long _index = 0;


	// Program info
	std::string _result = "";

	std::vector<JumpAttr> _jumps;
	unsigned _jumpNum = 0;


	// Error code
	int _error = 0;

public:

	Compress(const char* path);


	// Run the compressor
	int run();


	// Write the result
	int write(const char* path);


	// Get the message from an error code
	static const char* errorMessage(int code);

};