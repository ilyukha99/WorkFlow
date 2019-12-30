#define CRT_SECURE_NO_WARNINGS
#include "WorkFlow.h"

int main() {

	WorkFlow workflow;
	try {
		workflow.session("workflow.txt");
	}
	catch (char* str) {
		std::cout << str << "\n";
	}

	system("pause");
	return 0;
}
//Parser P("workflow.txt");
//try {
//	P.Parse();
//}
//catch (char* str) {
//	std::cout << str << std::endl;
//}