#pragma once

#include "AbstractProductA.h"

class ConcreteProductA2 : public AbstractProductA
{
    std::string usefulFunctionA() const override;
};
