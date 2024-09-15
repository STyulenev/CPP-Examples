#include "ConcreteClass1.h"

#include <iostream>

void ConcreteClass1::requiredAction1() const
{
    std::cout << "  ConcreteClass1::requiredAction1()" << std::endl;
}

void ConcreteClass1::requiredAction2() const
{
    std::cout << "  ConcreteClass1::requiredAction2()" << std::endl;
}
