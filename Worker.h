#pragma once
#include <vector>

enum Worker_id {in, out, in_out};

class Worker {

public:
	virtual ~Worker() = default;
	virtual Worker_id get_type() = 0;
	virtual Worker* operation(std::string & instructions, std::vector<std::string> & text) = 0;
};