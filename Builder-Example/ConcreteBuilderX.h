#pragma once

#include "AbstractBuilder.h"

class ConcreteBuilderX : public AbstractBuilder
{
public:
    ConcreteBuilderX();
    ~ConcreteBuilderX();

    void buildPartA() override;
    void buildPartB() override;
    void buildPartC() override;
    // ...

};
