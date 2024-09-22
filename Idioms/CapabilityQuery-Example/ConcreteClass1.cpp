#include "ConcreteClass1.h"

#include <iostream>

ConcreteClass1::ConcreteClass1()
{
    std::cout << "ConcreteClass1::ConcreteClass1()" << std::endl;
}

ConcreteClass1::~ConcreteClass1()
{
    std::cout << "ConcreteClass1::~ConcreteClass1()" << std::endl;
}

void ConcreteClass1::method_1() const
{
    std::cout << "ConcreteClass1::method_1()" << std::endl;
}

void ConcreteClass1::method_2()
{
    std::cout << "ConcreteClass1::method_2()" << std::endl;
}
