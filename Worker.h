#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

enum Type {in, out, in_out};

class Worker {

public:
	
	virtual ~Worker() = default;
	virtual std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text) = 0;
	virtual Type type() const = 0;
};