#include "ConcreteComponentB.h"

#include "VisitorInterface.h"

void ConcreteComponentB::someAction(VisitorInterface *visitor) const
{
    visitor->visitConcreteComponentB(this);
}

std::string ConcreteComponentB::someActionConcreteComponentB() const
{
    return "B";
}
