#pragma once
#include "Validator.h"

struct Info {

	int number;
	std::string command;
	std::vector<std::string> operands;
};

class Parser {

	const std::string _file_name;
	std::vector<Validator*> _variants;

	std::vector<Info> _instructions;
	std::vector<int> _execution_order;
public:

	Parser(const std::string & file_name);
	void Parse();
	std::vector<Info> instructions() const;
	std::vector<int> execution_order() const;
};