#pragma once
#include <string>
#include <vector>

struct Validator {

	Validator() = default;
	virtual bool is_support(const std::string & name) const = 0 ;
	virtual bool arguments_correctness(const std::vector<std::string> & operands) const = 0;
	virtual ~Validator() = default;
};

struct ValidReader : public Validator {

	ValidReader() {}
	bool is_support(const std::string & name) const;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidReader() {}
};

struct ValidWriter : public Validator {

	ValidWriter() {}
	bool is_support(const std::string & name) const ;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidWriter() {}
};

struct ValidGrep : public Validator {

	ValidGrep() {}
	bool is_support(const std::string & name) const;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidGrep() {}
};

struct ValidSort : public Validator {

	ValidSort() {}
	bool is_support(const std::string & name) const;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidSort() {}
};

struct ValidReplace : public Validator {

	ValidReplace() {}
	bool is_support(const std::string & name) const;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidReplace() {}
};

struct ValidDump : public Validator {

	ValidDump() {}
	bool is_support(const std::string & name) const;
	bool arguments_correctness(const std::vector<std::string> & operands) const;
	~ValidDump() {}
};