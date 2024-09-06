#pragma once

#include "AbstractBuilder.h"

class Director
{
public:
    Director();
    ~Director();

    void set(AbstractBuilder* builder);
    Product get();

    void construct();
    // ...

private:
    AbstractBuilder* builder;

};
