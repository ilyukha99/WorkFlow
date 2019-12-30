#include "Reader.h"
#include "BlockMaker.h"

static BlockMaker<Reader> readMaker("readfile");

Type Reader::type() const {
	return _type;
}

std::vector<std::string> Reader::operation(const std::vector<std::string> & args, const std::vector<std::string> & text) {

	std::string file_name(args[0]);
	std::ifstream file(file_name);

	try {
		if (!file.is_open())
			throw "Error opening file!";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	std::vector<std::string> new_text;
	std::string buffer = "";

	while (!file.eof()) {
		std::getline(file, buffer);
		new_text.push_back(buffer);
	}

	file.close();
	return new_text;
}

