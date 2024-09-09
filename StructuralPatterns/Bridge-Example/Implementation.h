#pragma once

#include <string>

class Implementation
{
public:
    Implementation() {}
    virtual ~Implementation() {}

    virtual std::string operationImplementation() const = 0;

};
