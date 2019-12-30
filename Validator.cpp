#include "Validator.h"

bool ValidReader::is_support(const std::string & name) const {
	if (name == "readfile")
		return true;
	return false;
}

bool ValidReader::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 1 && operands[0] != "")
		return true;
	return false;
}

bool ValidWriter::is_support(const std::string & name) const {
	if (name == "writefile")
		return true;
	return false;
}

bool ValidWriter::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 1 && operands[0] != "")
		return true;
	return false;
}

bool ValidGrep::is_support(const std::string & name) const {
	if (name == "grep")
		return true;
	return false;
}

bool ValidGrep::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 1 && operands[0] != "")
		return true;
	return false;
}

bool ValidSort::is_support(const std::string & name) const {
	if (name == "sort")
		return true;
	return false;
}

bool ValidSort::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 0)
		return true;
	return false;
}

bool ValidReplace::is_support(const std::string & name) const {
	if (name == "replace")
		return true;
	return false;
}

bool ValidReplace::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 2)
		return true;
	return false;
}

bool ValidDump::is_support(const std::string & name) const {
	if (name == "dump")
		return true;
	return false;
}

bool ValidDump::arguments_correctness(const std::vector<std::string> & operands) const {
	if (operands.size() == 1 && operands[0] != "")
		return true;
	return false;
}