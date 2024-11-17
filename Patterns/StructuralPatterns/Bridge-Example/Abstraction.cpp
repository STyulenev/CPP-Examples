#include "Abstraction.h"

Abstraction::Abstraction(Implementation* implementation) :
    implementation_(implementation)
{
    // ...
}

Abstraction::~Abstraction()
{
    // ...
}

std::string Abstraction::operation() const
{
    return "Abstraction ... + " + this->implementation_->someOperation();
}
