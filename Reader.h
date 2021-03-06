#pragma once
#include "Worker.h"

class Reader : public Worker {

	Type _type = in;
public:

	Reader() = default;
	std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text);
	Type type() const;
	~Reader() = default;
};