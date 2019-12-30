#pragma once
#include "Factory.h"

template<typename T>
class BlockMaker : public IBlockMaker {

public:

    BlockMaker(const std::string & name) {
        Factory::Instance().RegisterMaker(name, this);
    }

    virtual Worker* Create() const {
        return new T();
    }
};
