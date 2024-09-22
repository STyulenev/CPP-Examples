#include "ConcreteClass.h"

#include <iostream>

ConcreteClass::ConcreteClass(int parameter) :
    AbstractBase(parameter)
{
    std::cout << "ConcreteClass::ConcreteClass" << std::endl;
}

ConcreteClass::~ConcreteClass()
{
    std::cout << "ConcreteClass::~ConcreteClass" << std::endl;
}

void ConcreteClass::method_1() const
{
    std::cout << "method_1" << std::endl;
}

void ConcreteClass::method_2() const
{
    std::cout << "method_2" << std::endl;
}
