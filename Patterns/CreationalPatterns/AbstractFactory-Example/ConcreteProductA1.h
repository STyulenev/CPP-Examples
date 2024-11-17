#pragma once

#include "AbstractProductA.h"

class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string usefulFunctionA() const override;

};
