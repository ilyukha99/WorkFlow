#pragma once
#include "Validator.h"
#include <fstream>
#include <iostream>
#include <locale>

struct Info {

	int number;
	std::string command;
	std::vector<std::string> operands;
};

class Parser {

	const std::string _file_name;
	std::vector<Info> _instructions;
	std::vector<Validator*> _variants;
	std::vector<int> _execution_order;
public:

	Parser(const std::string & file_name);
	void Parse();
	std::vector<Info> instructions() const;
	std::vector<int> Parser::execution_order() const;
};