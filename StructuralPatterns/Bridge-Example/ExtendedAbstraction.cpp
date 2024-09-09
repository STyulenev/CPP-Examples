#include "ExtendedAbstraction.h"

ExtendedAbstraction::ExtendedAbstraction(Implementation* implementation) :
    Abstraction(implementation)
{

}

std::string ExtendedAbstraction::operation() const
{
    return "ExtendedAbstraction: Extended operation with: " + this->implementation_->operationImplementation();
}
