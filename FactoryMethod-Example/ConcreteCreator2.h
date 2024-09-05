#pragma once

#include "AbstractCreator.h"
#include "AbstractProduct.h"

class ConcreteCreator2 : public Creator
{
public:
    ConcreteCreator2();
    ~ConcreteCreator2();

    AbstractProduct* factoryMethod() const override;

};
