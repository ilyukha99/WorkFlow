#include "Sort.h"
#include "BlockMaker.h"
#include <algorithm>

static BlockMaker<Sort> sortMaker("sort");

std::vector<std::string> Sort::operation(const std::vector<std::string> & args, const std::vector<std::string> & text) {
	
	std::vector<std::string> my_vector(text);

	std::sort(my_vector.begin(), my_vector.end(), compare_strings);
	return my_vector;
}

Type Sort::type() const {
	return _type;
}
