#pragma once

#include "AbstractProduct.h"

class ConcreteProduct1 : public AbstractProduct
{
public:
    ConcreteProduct1();
    ~ConcreteProduct1();

    std::string operation() const override;

};
