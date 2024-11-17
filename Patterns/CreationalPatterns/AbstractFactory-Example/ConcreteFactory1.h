#pragma once

#include "AbstractFactory.h"

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() const override;
    AbstractProductB* createProductB() const override;

};
