#include "ConcreteCreator1.h"
#include "ConcreteProduct1.h"

ConcreteCreator1::ConcreteCreator1()
{
// ...
}

ConcreteCreator1::~ConcreteCreator1()
{
// ...
}

AbstractProduct* ConcreteCreator1::factoryMethod() const
{
    return new ConcreteProduct1();
}
