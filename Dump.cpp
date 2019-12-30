#include "Dump.h"
#include "BlockMaker.h"

static BlockMaker<Dump> dumpMaker("dump");

std::vector<std::string> Dump::operation(const std::vector<std::string> & args, const std::vector<std::string> & text) {
	
	std::ofstream file(args[0]);
	std::vector<std::string> my_vector(text);

	try {
		if (!file.is_open())
			throw "Error opening file!";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	for (size_t it = 0; !file.eof(); ++it)
		file << my_vector[it] << "\n";

	file.close();
	return my_vector;
}

Type Dump::type() const {
	return _type;
}
