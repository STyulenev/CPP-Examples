#include "ConcreteComponentA.h"

#include "VisitorInterface.h"

void ConcreteComponentA::someAction(VisitorInterface* visitor) const
{
    visitor->visitConcreteComponentA(this);
}

std::string ConcreteComponentA::someActionConcreteComponentA() const
{
    return "A";
}
