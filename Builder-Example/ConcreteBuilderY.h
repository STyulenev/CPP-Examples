#pragma once

#include "AbstractBuilder.h"

class ConcreteBuilderY : public AbstractBuilder
{
public:
    ConcreteBuilderY();
    ~ConcreteBuilderY();

    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;
    // ...
};
