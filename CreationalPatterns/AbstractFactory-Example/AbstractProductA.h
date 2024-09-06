#pragma once

#include <string>

class AbstractProductA
{
public:
    AbstractProductA() {};
    virtual ~AbstractProductA() {};

    virtual std::string usefulFunctionA() const = 0;

};
