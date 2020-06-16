#pragma once

#include <fstream>
#include <string>


namespace File {

	// Read a file
	std::string read(const char* path, int* error);


	// Assemble a program string
	std::string getProgram(const char* path, int* error);

}