#pragma once

#include <string>

class AbstractProduct
{
public:
    AbstractProduct() {}
    virtual ~AbstractProduct() {}

    virtual std::string operation() const = 0;
};
