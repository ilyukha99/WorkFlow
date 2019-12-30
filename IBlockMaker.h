#pragma once
#include "Worker.h"

class IBlockMaker {

public:

	virtual Worker* Create() const = 0;
	virtual ~IBlockMaker() = default;
};