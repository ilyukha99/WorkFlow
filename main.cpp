#include "Parser.h"

int main() {

	Parser P("workflow.txt");

	try {
		P.Parse();
	}
	catch (char* str) {
		std::cout << str << std::endl;
	}

	system("pause");
	return 0;
}