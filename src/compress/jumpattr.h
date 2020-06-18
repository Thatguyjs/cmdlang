#pragma once

#include <string>


struct JumpAttr {
	std::string _name = "";
	std::string _alias = "";

	JumpAttr(std::string name, std::string alias): _name(name), _alias(alias) {}
};