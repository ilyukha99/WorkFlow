#pragma once
#include "Worker.h"

class Dump : public Worker{

	Type _type = out;
public:

	Dump() = default;
	std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text);
	Type type() const;
	~Dump() = default;
};