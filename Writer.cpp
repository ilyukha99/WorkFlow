#include "Writer.h"
#include "BlockMaker.h"

static BlockMaker<Writer> writeMaker("writefile");

std::vector<std::string> Writer::operation(const std::vector<std::string> & args, const std::vector<std::string> & text) {
	
	std::vector<std::string> my_vector(text);
	std::ofstream file(args[0]);

	try {
		if (!file.is_open())
			throw "Error opening file!";
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	for (size_t it = 0; it != my_vector.size(); ++it)
		file << my_vector[it] << "\n";

	file.close();
	return my_vector;
}

Type Writer::type() const {
	return _type;
}
