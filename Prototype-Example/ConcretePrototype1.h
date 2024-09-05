#pragma once

#include "AbstractPrototype.h"

class ConcretePrototype1 : public AbstractPrototype
{
private:
    float concretePrototypeField1_;

public:
    ConcretePrototype1();
    ConcretePrototype1(std::string prototypeName, float concretePrototypeField);
    ~ConcretePrototype1();

    AbstractPrototype* clone() const override;
};
