#pragma once

#include "AbstractPrototype.h"

class ConcretePrototype2 : public AbstractPrototype
{
private:
    float concretePrototypeField2_;

public:
    ConcretePrototype2();
    ConcretePrototype2(std::string prototypeName, float concretePrototypeField);
    ~ConcretePrototype2();

    AbstractPrototype* clone() const override;

};
