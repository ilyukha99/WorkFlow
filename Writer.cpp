#include "Writer.h"

Writer::Writer(const std::string & file_name) : _output_file_name(file_name) {
}

Worker_id Writer::get_type() {
	return Writer::type;
}

Worker* Writer::operation(std::string & instructions, std::vector<std::string> & text) {
	
	std::ofstream output_file(_output_file_name);
	for (int it = 0; !output_file.eof(); ++it) {
		output_file << text[it];
	}
	return this;
}

Writer::~Writer() {
}