#pragma once

#include "AbstractProduct.h"

class ConcreteProduct2 : public AbstractProduct
{
public:
    ConcreteProduct2();
    ~ConcreteProduct2();

    std::string operation() const override;

};
