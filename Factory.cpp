#include "Factory.h"

Factory& Factory::Instance() {

	static Factory factory;
	return factory;
}

void Factory::RegisterMaker(const std::string & name, IBlockMaker* maker) {

	if (_makers.find(name) != _makers.end()) {
		throw new std::exception("Multiple makers for given key!");
	}

	_makers[name] = maker;
}

Worker* Factory::Create(const std::string & block_name) const {

	auto block = _makers.find(block_name);

	if (block == _makers.end()) {
		throw new std::exception("Unrecognized object type!");
	}

	IBlockMaker* maker = block->second;
	return maker->Create();
}
