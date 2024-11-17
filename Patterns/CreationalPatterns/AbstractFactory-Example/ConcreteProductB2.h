#pragma once

#include "AbstractProductA.h"
#include "AbstractProductB.h"

class ConcreteProductB2 : public AbstractProductB
{
public:
    std::string usefulFunctionB() const override;

    std::string anotherUsefulFunctionB(const AbstractProductA &collaborator) const override;

};
