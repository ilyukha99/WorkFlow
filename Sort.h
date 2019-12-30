#pragma once
#include "Worker.h"

class Sort : public Worker {

	Type _type = in_out;
public:

	Sort() = default;
	std::vector<std::string> operation(const std::vector<std::string> & args, const std::vector<std::string> & text);
	Type type() const;
	~Sort() = default;
};

struct Strings_compare {

	bool operator() (std::string str1, std::string str2) {

		for (unsigned it = 0; it != str1.length() || it != str2.length(); ++it) {

			if (str1[it] == str2[it])
				continue;

			if (it == str1.length() && it != str2.length())
				return true;
			else if ((it != str1.length() && it == str2.length()) || it == str1.length() == str2.length())
				return false;

			return (str1[it] < str2[it]);
		}
		return 0;
	}
} compare_strings;

//bool strings_compare(std::string str1, std::string str2) {
//		
//	for (unsigned it = 0; it != str1.length() || it != str2.length(); ++it) {
//
//		if (str1[it] == str2[it])
//			continue;
//
//		if (it == str1.length() && it != str2.length())
//			return true;
//		else if ((it != str1.length() && it == str2.length()) || it == str1.length() == str2.length()) 
//			return false;
//
//		return (str1[it] < str2[it]);
//	}
//	return 0;
//}