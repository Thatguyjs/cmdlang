#pragma once

#include <string>


struct Jump {
	unsigned long _index = 0;
	std::string _name = "";

	Jump(unsigned long index, std::string name) : _index(index), _name(name) {}
};