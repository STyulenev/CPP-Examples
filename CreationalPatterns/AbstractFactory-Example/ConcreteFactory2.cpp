#include "ConcreteFactory2.h"

#include "ConcreteProductA2.h"
#include "ConcreteProductB2.h"

AbstractProductA* ConcreteFactory2::createProductA() const
{
    return new ConcreteProductA2();
}

AbstractProductB* ConcreteFactory2::createProductB() const
{
    return new ConcreteProductB2();
}
