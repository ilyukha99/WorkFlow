#include "Reader.h"

Reader::Reader(const std::string & file_name) : _input_file_name(file_name) {
}

Worker_id Reader::get_type() {
	return Reader::type;
}

Worker* Reader::operation(const std::string & instructions, const std::vector<std::string> & text) {

	std::ifstream input_file(_input_file_name);
	std::string buffer = "";
	for (int it = 0; !input_file.eof(); ++it) {
		getline(input_file, buffer);
		_text.push_back(buffer);
	}
	return this;
}

Reader::~Reader() {
}