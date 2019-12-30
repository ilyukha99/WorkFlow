#pragma once
#include "Worker.h"
#include "IBlockMaker.h"

class Factory {

	std::map<std::string, IBlockMaker*> _makers;
public:

	void RegisterMaker(const std::string & name, IBlockMaker* maker);
	static Factory & Instance();
	Worker* Create(const std::string & block_name) const;
	~Factory() = default;
};
