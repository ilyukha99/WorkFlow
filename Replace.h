#pragma once
#include "Worker.h"

class Replace : public Worker {

	Type _type = in_out;
public:

	Replace() = default;
	std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text);
	Type type() const;
	~Replace() = default;
};