#pragma once

#include "AbstractCreator.h"
#include "AbstractProduct.h"

class ConcreteCreator1 : public Creator
{
public:
    ConcreteCreator1();
    ~ConcreteCreator1();

    AbstractProduct* factoryMethod() const override;

};
