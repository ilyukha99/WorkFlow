#pragma once
#include "Worker.h"

class Writer : public Worker {

	const static Worker_id type = out;
	std::string _output_file_name;
public:

	Writer(const std::string & file_name);
	~Writer();
	static Worker_id get_type();
	Worker* operation(std::string & instructions, std::vector<std::string> & text);
};