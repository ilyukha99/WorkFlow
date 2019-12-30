#include "Workflow.h"

void WorkFlow::session(const std::string & file_name) {

	Parser parser(file_name);
	parser.Parse();
	std::vector<int> order(parser.execution_order());
	std::vector<Info> instructions(parser.instructions());

	Factory factory = Factory::Instance();
	std::vector<std::string> result;

	for (unsigned iterator = 0; iterator != order.size(); ++iterator) {
		for (unsigned it = 0; it != instructions.size(); ++it) {
			if (instructions[it].number == order[iterator]) {
				Worker* Block = factory.Create(instructions[it].command);
				result = Block->operation(instructions[it].operands, result);

				delete Block;
				break;
			}
		}
	}
}