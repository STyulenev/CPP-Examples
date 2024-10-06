#include "Adapter.h"

#if (MULTIPLE_INHERITANCE)

Adapter::Adapter(Adaptee* adaptee) :
    adaptee_(adaptee)
{
    // ...
}

Adapter::~Adapter()
{
    // ...
}

std::string Adapter::someAction() const
{
    return this->adaptee_->specialAction() + " + with processing + " + Target::someAction();
}

#else

Adapter::Adapter()
{
    // ...
}

Adapter::~Adapter()
{
    // ...
}

std::string Adapter::someAction() const
{
    return Adaptee::specialAction() + " + with processing + " + Target::someAction();
}

#endif
