#include "Replace.h"
#include "BlockMaker.h"

static BlockMaker<Replace> replaceMaker("replace");

Type Replace::type() const {
	return _type;
}

std::vector<std::string> Replace::operation(const std::vector<std::string> & args, const std::vector<std::string> & text) {

	std::string word1(args[0]), word2(args[1]), buffer;
	std::vector<std::string> my_vector(text), new_text;
	unsigned i, wlength;
	wlength = word1.length();

	for (unsigned iterator = 0; iterator != my_vector.size(); ++iterator) {
		buffer = my_vector[iterator];
		for (unsigned it = 0; it != buffer.length(); ++it)
			if (buffer[it] == word1[0]) {
				for (i = 1; i != wlength; ++i)
					if (buffer[it + i] == word1[i])
						continue;
					else break;

				if (i == wlength) {
					buffer.erase(it, wlength);
					buffer.insert(it, word2);
				}
			}
		new_text.push_back(buffer);
	}
	return new_text;
}