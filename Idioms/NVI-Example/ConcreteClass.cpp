#include "ConcreteClass.h"

#include <iostream>

ConcreteClass::ConcreteClass()
{

}

ConcreteClass::~ConcreteClass()
{

}

void ConcreteClass::someActionImpl()
{
    std::cout << "ConcreteClass::someActionImpl()" << std::endl;
}
