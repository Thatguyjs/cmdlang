#include "compress.h"


Compress::Compress(const char* path) {
	this->_path = path;
	this->_data = File::getProgram(path, &this->_error);
	this->_dataLength = this->_data.length();
}


// Run the compressor
int Compress::run() {
	while (this->_index < this->_dataLength && !this->_error) {

		// Optimize commands
		if (this->_data[this->_index] == '<' && this->_data[this->_index + 1] == '>') {
			this->_index += 2;
			continue;
		}
		else if (this->_data[this->_index] == '>' && this->_data[this->_index + 1] == '<') {
			this->_index += 2;
			continue;
		}
		else if (this->_data[this->_index] == '+' && this->_data[this->_index + 1] == '-') {
			this->_index += 2;
			continue;
		}
		else if (this->_data[this->_index] == '-' && this->_data[this->_index + 1] == '+') {
			this->_index += 2;
			continue;
		}


		// Add commands
		switch (this->_data[this->_index]) {

		// Whitespace
		case ' ':
		case '\t':
		case '\r':
		case '\n':
			this->_index++;
			break;


		// Single-line comment
		case '/':
			while (this->_data[++this->_index] != '\n');
			this->_index++;
			break;


		// Single character commands
		case '+':
		case '-':
		case '>':
		case '<':
		case '[':
		case ']':
		case ',':
		case '.':
		case ':':
		case ')':
		case '#':
		case ';':
			this->_result += this->_data[this->_index++];
			break;


		// Create a jump point
		case '!':
			{
				std::string name = "";
				this->_result += '!';

				while (this->_data[++this->_index] != ';') {
					name += this->_data[this->_index];
				}

				bool found = false;

				for (unsigned i = 0; i < this->_jumpNum; i++) {
					if (name == this->_jumps[i]._name.data()) {
						found = true;
						this->_result += this->_jumps[i]._alias;
						break;
					}
				}

				if(!found) {
					this->_result += std::to_string(this->_jumpNum);

					this->_jumps.push_back(JumpAttr(name, std::to_string(this->_jumpNum)));
					this->_jumpNum++;
				}

				this->_result += ';';
				this->_index++;
			}
			break;

		// Go to a jump point
		case '@':
			{
				std::string name = "";
				this->_result += '@';

				while (this->_data[++this->_index] != ';') {
					name += this->_data[this->_index];
				}

				bool found = false;

				for (unsigned i = 0; i < this->_jumpNum; i++) {
					if (name == this->_jumps[i]._name.data()) {
						found = true;
						this->_result += this->_jumps[i]._alias;
						break;
					}
				}

				if (!found) {
					this->_result += std::to_string(this->_jumpNum);

					this->_jumps.push_back(JumpAttr(name, std::to_string(this->_jumpNum)));
					this->_jumpNum++;
				}

				this->_result += ';';
				this->_index++;
			}
			break;


		// Check cell equality
		case '=':
			this->_result += '=';

			while (this->_data[this->_index++] != '(') {
				if (this->_data[this->_index] == ' ') continue;

				this->_result += this->_data[this->_index];
			}
			break;


		// Debugging output
		case '{':
			this->_result += '{';

			while (this->_data[this->_index++] != '}') {
				this->_result += this->_data[this->_index];
			}
			break;


		// Print memory
		case '$':
			this->_result += '$';

			while (this->_data[this->_index++] != ';') {
				if (this->_data[this->_index] == ' ') continue;

				this->_result += this->_data[this->_index];
			}
			break;


		// Unknown character
		default:
			std::cout << "Index: " << this->_index << std::endl;
			this->_error = 2;
			break;

		}
	}


	return this->_error;
}


// Write the result
int Compress::write(const char* path) {
	if (this->_error) return this->_error;

	std::fstream file = File::create(path, &this->_error);

	if (this->_error) return this->_error;

	file << this->_result;
	file.close();

	return this->_error;
}


// Get the error message from an error code
const char* Compress::errorMessage(int code) {
	switch (code) {

	case 0:
		return "Success";

	case 1:
		return "File not found";

	case 2:
		return "Unknown character";

	case 3:
		return "Unable to create file";

	default:
		return "Unknown error";

	}
}