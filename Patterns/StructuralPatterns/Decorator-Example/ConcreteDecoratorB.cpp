#include "ConcreteDecoratorB.h"

ConcreteDecoratorB::ConcreteDecoratorB(AbstractComponent* component) :
    Decorator(component)
{
    // ...
}

std::string ConcreteDecoratorB::operation() const
{
    return "ConcreteDecoratorB(" + Decorator::operation() + ")";
}
