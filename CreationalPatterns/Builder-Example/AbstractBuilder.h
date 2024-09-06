#pragma once

#include "Product.h"

class AbstractBuilder
{
public:
    AbstractBuilder() {}
    virtual ~AbstractBuilder() {}

    Product get() {
        return product;
    }

    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    // ...

protected:
    Product product;

};
