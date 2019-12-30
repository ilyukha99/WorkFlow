#pragma once
#include "Worker.h"

class Writer : public Worker {

	Type _type = out;
public:

	Writer() = default;
	std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text);
	Type type() const;
	~Writer() = default;
};