#include "ConcretePrototype1.h"

ConcretePrototype1::ConcretePrototype1()
    //: ...
{
    // ...
}

ConcretePrototype1::ConcretePrototype1(std::string prototypeName, float concretePrototypeField) :
    AbstractPrototype(prototypeName),
    concretePrototypeField1_(concretePrototypeField)
{
    // ...
}

ConcretePrototype1::~ConcretePrototype1()
{
    // ...
}

AbstractPrototype* ConcretePrototype1::clone() const
{
    return new ConcretePrototype1(*this);
}
