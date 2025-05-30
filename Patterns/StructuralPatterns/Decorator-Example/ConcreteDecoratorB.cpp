#include "ConcreteDecoratorB.h"

ConcreteDecoratorB::ConcreteDecoratorB(AbstractComponent* component) :
    Decorator(component)
{
    // ...
}

ConcreteDecoratorB::~ConcreteDecoratorB()
{
    // ...
}

std::string ConcreteDecoratorB::operation() const
{
    return "ConcreteDecoratorB(" + Decorator::operation() + ")";
}
