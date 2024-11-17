#include "ExtendedAbstraction.h"

ExtendedAbstraction::ExtendedAbstraction(Implementation* implementation) :
    Abstraction(implementation)
{
    // ...
}

ExtendedAbstraction::~ExtendedAbstraction()
{
    // ...
}

std::string ExtendedAbstraction::operation() const
{
    return Abstraction::operation() + " + ExtendedAbstraction ... + " + this->implementation_->someOperation();
}
