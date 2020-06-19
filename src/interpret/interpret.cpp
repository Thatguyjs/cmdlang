#include "interpret.h"


Interpreter::Interpreter(const char* path) {
	this->_path = path;
	this->_data = File::getProgram(path, &this->_error);
	this->_dataLength = this->_data.length();

	// TODO: Adjustable size
	this->_cells = new unsigned[30000];
	memset(this->_cells, 0, 30000);
	this->_cellNum = 30000;
}


// Run the program
int Interpreter::run() {
	while (this->_index < this->_dataLength && !this->_error) {
		switch (this->_data[this->_index]) {

		// Whitespace
		case '\r':
		case '\n':
		case ' ':
		case '\t':
			this->_index++;
			break;


		// Single-line comment
		case '/':
			while (this->_data[++this->_index] != '\n');
			this->_index++;
			break;


		// Increment the cell value
		case '+':
			this->_cells[this->_cell]++;
			this->_index++;
			break;

		// Decrement the cell value
		case '-':
			this->_cells[this->_cell]--;
			this->_index++;
			break;


		// Increment the cell address
		case '>':
			this->_cell++;
			this->_index++;

			if (this->_cell >= this->_cellNum) this->_error = 4;
			break;

		// Decrement the cell address
		case '<':
			this->_cell--;
			this->_index++;

			if (this->_cell < 0) this->_error = 4;
			break;


		// Jump forward or continue
		case '[':
			if (this->_cells[this->_cell] == 0) {
				int depth = 0;

				while (this->_data[++this->_index] != ']' || depth > 0) {
					if (this->_data[this->_index] == '[') depth++;
					else if (this->_data[this->_index] == ']') depth--;
				}
			}
			else {
				this->_index++;
			}
			break;

		// Jump back or continue
		case ']':
			if (this->_cells[this->_cell] == 0) {
				this->_index++;
			}
			else {
				int depth = 0;

				while (this->_data[--this->_index] != '[' || depth > 0) {
					if (this->_data[this->_index] == ']') depth++;
					else if (this->_data[this->_index] == '[') depth--;
				}
			}
			break;


		// Create a new jump point
		case '!':
			{
				std::string name = "";

				while (this->_data[++this->_index] != ';') {
					name += this->_data[this->_index];
				}

				// Ignore if it already exists
				const char* rawName = name.data();
				bool found = false;

				for (int i = this->_jumpNum - 1; i >= 0; i--) {
					if (this->_jumps[i]._name == rawName) {
						found = true;
						this->_index++;
						break;
					}
				}

				if (found) break;

				// Add it to the list
				this->_jumps.push_back(Jump(++this->_index, name.data()));
				this->_jumpNum++;
			}
			break;

		// Go to a jump point
		case '@':
			{
				std::string name = "";

				while (this->_data[++this->_index] != ';') {
					name += this->_data[this->_index];
				}

				const char* rawName = name.data();

				for (int i = this->_jumpNum - 1; i >= 0; i--) {
					if (this->_jumps[i]._name == rawName) {
						this->_index = this->_jumps[i]._index;
						break;
					}
				}
			}
			break;


		// Check cell equality
		case '=':
			{
				while (this->_data[++this->_index] != '(');

				int number = 0;
				int digit = 1;

				while (this->_data[--this->_index] != '=') {
					if (this->_data[this->_index] == ' ') continue;

					number += (this->_data[this->_index] - 48) * digit;
					digit *= 10;
				}

				if (this->_cells[this->_cell] == number) {
					while (this->_data[++this->_index] != '(');
					this->_index++;
				}
				else {
					int depth = -1; // Account for the first opening parenthesis

					while (this->_data[++this->_index] != ')' || depth > 0) {
						if (this->_data[this->_index] == '(') depth++;
						else if (this->_data[this->_index] == ')') depth--;
					}

					this->_index++;
				}
			}
			break;

		// Ending of a statement
		case ')':
			this->_index++;
			break;


		// Input a character
		case ',':
			std::cin >> this->_cells[this->_cell];
			this->_index++;
			break;

		// Output a character
		case '.':
			std::cout << (char)this->_cells[this->_cell];
			this->_index++;
			break;

		// Output as a number
		case ':':
			std::cout << (unsigned)this->_cells[this->_cell];
			this->_index++;
			break;

		// Debugging output
		case '{':
			{
				std::string output = "";

				while (this->_data[++this->_index] != '}') {
					output += this->_data[this->_index];
				}

				std::cout << output;
			}

			this->_index++;
			break;


		// Add a breakpoint
		case '#':
			std::cout << "Cell " << this->_cell << " value " << (unsigned)this->_cells[this->_cell] << std::endl;
			this->_index++;

			std::getchar();
			break;

		// Print memory
		case '$':
			{
				unsigned start = 0;
				unsigned end = 0;
				int digit = 1;

				// Get numbers
				while (this->_data[++this->_index] != ';');

				while (this->_data[--this->_index] != ',') {
					if (this->_data[this->_index] == ' ') continue;

					end += (this->_data[this->_index] - 48) * digit;
					digit *= 10;
				}

				digit = 1;

				while (this->_data[--this->_index] != '$') {
					if (this->_data[this->_index] == ' ') continue;

					start += (this->_data[this->_index] - 48) * digit;
					digit *= 10;
				}

				// Print memory
				while (start < end) {
					std::cout << (unsigned)this->_cells[start] << ' ';
					start++;
				}

				std::cout << '\n';

				// Advance index
				while (this->_data[++this->_index] != ';');
				this->_index++;
			}
			break;


		// Terminate the program
		case ';':
			this->_error = 3;
			break;


		// Unknown character
		default:
			std::cout << "Index " << this->_index << std::endl;
			this->_error = 2;
			break;

		}
	}


	delete[] this->_cells;
	return this->_error;
}


// Get the error message from an error code
const char* Interpreter::errorMessage(int code) {
	switch (code) {

	case 0:
		return "Success";

	case 1:
		return "File not found";

	case 2:
		return "Unknown character";

	case 3:
		return "Program terminated";

	case 4:
		return "Cell pointer out of range";

	default:
		return "Unknown error";

	}
}