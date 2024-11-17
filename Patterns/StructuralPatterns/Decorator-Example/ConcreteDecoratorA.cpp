#include "ConcreteDecoratorA.h"

ConcreteDecoratorA::ConcreteDecoratorA(AbstractComponent* component) :
    Decorator(component)
{
    // ...
}

std::string ConcreteDecoratorA::operation() const
{
    return "ConcreteDecoratorA(" + Decorator::operation() + ")";
}
