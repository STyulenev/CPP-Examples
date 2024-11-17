#pragma once

#include "Decorator.h"

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(AbstractComponent* component);

    std::string operation() const override;

};
