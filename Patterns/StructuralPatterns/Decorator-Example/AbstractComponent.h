#pragma once

#include <string>

class AbstractComponent
{
public:
    virtual ~AbstractComponent() {}
    virtual std::string operation() const = 0;

};
