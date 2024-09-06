#include "ConcreteCreator2.h"
#include "ConcreteProduct2.h"

ConcreteCreator2::ConcreteCreator2()
{
    // ...
}

ConcreteCreator2::~ConcreteCreator2()
{
    // ...
}

AbstractProduct *ConcreteCreator2::factoryMethod() const
{
    return new ConcreteProduct2();
}
