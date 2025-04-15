#include "Decorator.h"

Decorator::Decorator(AbstractComponent* component) :
    component_(component)
{
    // ...
}

Decorator::~Decorator()
{
    // ...
}

// Пример минимальной обёртки
std::string Decorator::operation() const
{
    return "Decorator: " + this->component_->operation();
}
