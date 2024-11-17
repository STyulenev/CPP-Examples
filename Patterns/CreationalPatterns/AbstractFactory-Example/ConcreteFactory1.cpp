#include "ConcreteFactory1.h"

#include "ConcreteProductA1.h"
#include "ConcreteProductB1.h"

AbstractProductA* ConcreteFactory1::createProductA() const
{
    return new ConcreteProductA1();
}

AbstractProductB* ConcreteFactory1::createProductB() const
{
    return new ConcreteProductB1();
}
