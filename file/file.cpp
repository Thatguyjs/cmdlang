#include "file.h"


namespace File {

	std::string read(const char* path, int* error) {
		std::string result = "";

		std::fstream file(path);

		if (file.is_open()) {
			result.assign(
				std::istreambuf_iterator<char>(file),
				std::istreambuf_iterator<char>()
			);

			file.close();
		}
		else {
			*error = 1;
		}

		return result;
	}


	// Assemble a program string
	std::string getProgram(const char* path, int* error) {
		std::string base = File::read(path, error);
		if (*error) return base;

		std::string result = "";
		unsigned long length = base.length();
		unsigned long index = 0;

		// Remove comments & add linked files
		while (index < length) {
			if (base[index] == '/') {
				while (base[++index] != '\n');
			}
			else if (base[index] == '|') {
				std::string fpath = "";

				while (base[++index] != '|') {
					fpath += base[index];
				}

				result += File::read(fpath.data(), error);
				if (*error) return result;
			}
			else {
				result += base[index];
			}

			index++;
		}

		return result;
	}

}