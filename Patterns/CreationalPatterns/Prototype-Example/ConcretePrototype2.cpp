#include "ConcretePrototype2.h"

ConcretePrototype2::ConcretePrototype2()
    //: ...
{
    // ...
}

ConcretePrototype2::ConcretePrototype2(std::string prototypeName, float concretePrototypeField) :
    AbstractPrototype(prototypeName),
    concretePrototypeField2_(concretePrototypeField)
{
    // ...
}

ConcretePrototype2::~ConcretePrototype2()
{
    // ...
}

AbstractPrototype* ConcretePrototype2::clone() const
{
    return new ConcretePrototype2(*this);
}
