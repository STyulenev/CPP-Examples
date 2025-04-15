#include "ConcreteDecoratorA.h"

ConcreteDecoratorA::ConcreteDecoratorA(AbstractComponent* component) :
    Decorator(component)
{
    // ...
}

ConcreteDecoratorA::~ConcreteDecoratorA()
{
    // ...
}

std::string ConcreteDecoratorA::operation() const
{
    return "ConcreteDecoratorA(" + Decorator::operation() + ")";
}
