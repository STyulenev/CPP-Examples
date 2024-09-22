#include "ConcreteClass2.h"

#include <iostream>

ConcreteClass2::ConcreteClass2()
{
    std::cout << "ConcreteClass2::ConcreteClass2()" << std::endl;
}

ConcreteClass2::~ConcreteClass2()
{
    std::cout << "ConcreteClass2::~ConcreteClass2()" << std::endl;
}

void ConcreteClass2::method_1() const
{
    std::cout << "ConcreteClass1::method_1()" << std::endl;
}
