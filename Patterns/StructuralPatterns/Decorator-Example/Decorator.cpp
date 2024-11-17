#include "Decorator.h"

Decorator::Decorator(AbstractComponent* component) :
    component_(component)
{
    // ...
}

std::string Decorator::operation() const
{
    return this->component_->operation();
}
