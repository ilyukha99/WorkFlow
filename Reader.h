#pragma once
#include "Worker.h"

class Reader : public Worker {

	const static Worker_id type = in;
	std::string _input_file_name;
	std::vector<std::string> _text;
public:

	Reader(const std::string & file_name);
	static Worker_id get_type();
	~Reader();
	Worker* operation(const std::string & instructions, const std::vector<std::string> & text);
};