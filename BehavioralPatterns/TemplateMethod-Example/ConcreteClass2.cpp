#include "ConcreteClass2.h"

#include <iostream>

void ConcreteClass2::requiredAction1() const
{
    std::cout << "  ConcreteClass2::requiredAction1()" << std::endl;
}

void ConcreteClass2::requiredAction2() const
{
    std::cout << "  ConcreteClass2::requiredAction2()" << std::endl;
}

void ConcreteClass2::optionalAction1() const
{
    std::cout << "  ConcreteClass2::optionalAction1()" << std::endl;
}
