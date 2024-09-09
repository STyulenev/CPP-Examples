#pragma once

#include "Decorator.h"

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(AbstractComponent* component);

    std::string operation() const override;

};
