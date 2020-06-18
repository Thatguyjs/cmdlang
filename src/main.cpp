#include "interpret/interpret.h"
#include "compress/compress.h"

#include <iostream>


int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}


	// Commands
	unsigned cmdNum = 3;

	const char* cmdNames[3] = {
		"-r [path]",
		"-m [path] [out]",
		"-c [path] [out]"
	};

	const char* cmdDescs[3] = {
		"Interpret (run) a program",
		"Compress a program",
		"Transpile a program to C"
	};


	// General help
	if (!strcmp(argv[1], "-help")) {
		if (argc == 2) {
			for (unsigned i = 0; i < cmdNum; i++) {
				std::cout << cmdNames[i] << "\t\t" << cmdDescs[i] << std::endl;
			}

			return 0;
		}
		else {
			for (unsigned i = 0; i < cmdNum; i++) {
				if (argv[2][0] == cmdNames[i][1]) {
					std::cout << cmdNames[i] << "\t\t" << cmdDescs[i] << std::endl;
					return 0;
				}
			}

			std::cout << "Unknown command. Type -help for a list of commands" << std::endl;
			return 0;
		}
	}


	// Check for the commmand
	if (argv[1][1] == 'r') {
		Interpreter myInt(argv[2]);

		int error = myInt.run();

		if (error) {
			std::cout << "Error: [" << error << "]: " << Interpreter::errorMessage(error) << std::endl;
			system("pause");
			return error;
		}
	}
	else if (argv[1][1] == 'm') {
		Compress myComp(argv[2]);

		int error = myComp.run();
		error = myComp.write(argv[3]);

		if (error) {
			std::cout << "Error: [" << error << "]: " << Compress::errorMessage(error) << std::endl;
			system("pause");
			return error;
		}
	}
	else if (argv[1][1] == 'c') {
		std::cout << "Transpile program" << std::endl;
	}
	else {
		std::cout << "Unknown command. Type -help for a list of commands" << std::endl;
	}

	system("pause");
	return 0;
}