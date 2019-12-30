#pragma once
#include "Worker.h"

class Grep : public Worker {

	Type _type = in_out;
public:

	Grep() = default;
	std::vector<std::string> operation(const std::vector<std::string> & agrs, const std::vector<std::string> & text);
	Type type() const;
	~Grep() = default;
};