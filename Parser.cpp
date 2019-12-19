#include "Parser.h"

Parser::Parser(const std::string & file_name) : _file_name(file_name) {

	std::vector<Validator*> variants(6);
	variants[0] = new ValidReader;
	variants[1] = new ValidWriter;
	variants[2] = new ValidGrep;
	variants[3] = new ValidSort;
	variants[4] = new ValidReplace;
	variants[5] = new ValidDump;
	_variants = variants;
}
/*std::vector<Info> instructions(0);
_instructions = instructions;*/
//_instructions.reserve(0);

void Parser::Parse() {

	std::string buffer;
	std::string tmp;
	int iterator = 0, i;
	std::ifstream file(_file_name);

	try {
		if (!file.is_open())
			throw("Error opening file!");
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	getline(file, buffer);
	for (int it = 0; buffer == ""; ++it) // passing all empty lines before desc
		getline(file, buffer);

	try {
		if (buffer != "desc")
			throw("\"desc\" wasn't found!");
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	// parsing command lines
	for (iterator = 0; buffer != "csed" && !file.eof(); ++iterator) {

		getline(file, buffer);
		if (buffer == "csed")
			break;

		if (buffer == "")
			continue;

		_instructions.resize(iterator + 1);
		tmp = "";
		for (i = 0; isdigit(buffer[i]); ++i) // Getting the number
			tmp += buffer[i];

		try {
			if (tmp.empty())
				throw "The line must contain the command number!";
			_instructions[iterator].number = std::stoi(tmp);
		}
		catch (char* str) {
			std::cout << str << std::endl;
		}

		for (i; buffer[i] == ' ' && i != buffer.size(); ++i) // Running through spaces
			continue;

		try {
			if (buffer[i] != '=')
				throw "There should be a \"=\" sign";
			++i;
		}
		catch (char* str) {
			std::cout << str << std::endl;
		}

		for (i; buffer[i] == ' ' && i != buffer.size(); ++i) // Running through spaces
			continue;

		tmp = "";
		for (i; isalpha(buffer[i]); ++i) // Getting the command
			tmp += buffer[i];

		for (unsigned it = 0; it != 6; ++it) {
			if (_variants[it]->is_support(tmp)) {
				_instructions[iterator].command = tmp;
				break;
			}
		}

		try {
			if (_instructions[iterator].command.empty())
				throw "There is a nonexistent command in the list!";
		}
		catch (char* str) {
			std::cout << str << std::endl;
		}

		for (i; buffer[i] == ' ' && i != buffer.size(); ++i) // Running through spaces
			continue;

		// Getting all operands (0 or 1 or 2)

		if (tmp == "replace") {
			tmp = "";
			for (i; isalpha(buffer[i]); ++i)
				tmp += buffer[i];
			if (tmp != "")
				_instructions[iterator].operands.push_back(tmp);

			for (i; buffer[i] == ' ' && i != buffer.size(); ++i) // Running through spaces
				continue;

			tmp = "";
			for (i; isalpha(buffer[i]); ++i)
				tmp += buffer[i];
			if (tmp != "")
				_instructions[iterator].operands.push_back(tmp);

			try {
				if (_variants[4]->arguments_correctness(_instructions[iterator].operands) == 0)
					throw "Incorrect arguments set for \"replace\"!";
			}
			catch (char* str) {
				std::cout << str << std::endl;
			}
		}

		else if (tmp == "sort") {

			try {
				tmp = "";
				if (++i <= buffer.size()) {
					for (--i; isalpha(buffer[i]); ++i)
						tmp += buffer[i];
					if (tmp != "")
						_instructions[iterator].operands.push_back(tmp);
					if (_variants[3]->arguments_correctness(_instructions[iterator].operands) == 0)
						throw "\"Sort\" needs no arguments!";
				}
			}
			catch (char* str) {
				std::cout << str << std::endl;
			}
		}

		else {
			tmp = "";
			for (i; isalpha(buffer[i]) || buffer[i] == '.'; ++i)
				tmp += buffer[i];
			if (tmp != "")
				_instructions[iterator].operands.push_back(tmp);

			try {
				if (_variants[0]->arguments_correctness(_instructions[iterator].operands) == 0)
					throw "A mismatch in the number of a command arguments from one operand detected!";
			}
			catch (char* str) {
				std::cout << str << std::endl;
			}
		}
	}

	try {
		if (file.eof())
			throw "\"csed\" wasn't found!";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	_instructions.resize(iterator);

	// parsing the scheme
	for (iterator = 0; !file.eof(); ++iterator) {

		getline(file, buffer);
		if (buffer == "")
			continue;

		unsigned bsize = buffer.size();
		for (i = 0; i < bsize; ++i) {

		my_mark: for (i; buffer[i] == ' ' && i != bsize; ++i) // Running through spaces
			continue;

				 tmp = "";
				 for (i; isdigit(buffer[i]); ++i) // Getting the number
					 tmp += buffer[i];

				 try {
					 if (tmp == "")
						 throw "There must be a number of command before and after \"->\" !";
					 _execution_order.push_back(std::stoi(tmp));
				 }
				 catch (char* str) {
					 std::cout << str << std::endl;
				 }

				 for (i; buffer[i] == ' ' && i != bsize; ++i) // Running through spaces
					 continue;

				 tmp = "";
				 for (i; buffer[i] != ' ' && i != bsize; ++i)
					 tmp += buffer[i];

				 if (tmp == "->")
					 goto my_mark;
		}
	}

	try {
		for (int it = 0; it != _instructions.size(); ++it)
			if (_instructions[it].number == _execution_order.front() && _instructions[it].command != "readfile") 
				throw "The first command must be \"readfile\" !";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	try {
		for (int it = 0; it != _instructions.size(); ++it)
			if (_instructions[it].number == _execution_order.back() && _instructions[it].command != "writefile")
				throw "The last command must be \"writefile\" !";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}
}

//for (int it = 0; it != execution_order.size(); ++it)
//	std::cout << execution_order[it] << " ";

//for (int f = 0; f != _instructions.size(); ++f)
//	std::cout << _instructions[f].number << " " << _instructions[f].comand << " "
//	<< _instructions[f].operands[0] << "\n";

std::vector<int> Parser::execution_order() const {
	return _execution_order;
}

std::vector<Info> Parser::instructions() const {
	return _instructions;
}