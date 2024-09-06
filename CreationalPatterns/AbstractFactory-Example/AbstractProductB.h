#pragma once

#include <string>

#include "AbstractProductA.h"

class AbstractProductB
{
public:
    AbstractProductB() {};
    virtual ~AbstractProductB() {};

    virtual std::string usefulFunctionB() const = 0;

    virtual std::string anotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;

};
