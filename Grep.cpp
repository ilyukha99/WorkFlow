#include "Grep.h"
#include "BlockMaker.h"

static BlockMaker<Grep> grepMaker("grep");

std::vector<std::string> Grep::operation(const std::vector<std::string> & agrs, const std::vector<std::string> & text) {

	std::string word, tmp = "";
	std::vector<std::string> strings;
	std::vector<std::string> my_vector(text);
	unsigned slength, wlength, i;
	word = agrs[0];
	wlength = word.length();

	for (unsigned iterator = 0; iterator != my_vector.size(); ++iterator) {
		tmp = my_vector[iterator];
		slength = tmp.length();
		for (unsigned it = 0; it != slength; ++it)
			if (word[0] == tmp[it]) {
				for (i = 1; i != wlength; ++i) {
					if (word[i] == tmp[it + i])
						continue;
					else
						break;
				}
				if (wlength == i) {
					strings.push_back(tmp);
					break;
				}
			}
	}
	return strings;
}

Type Grep::type() const {
	return _type;
}
