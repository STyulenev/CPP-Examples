#include "ConcreteClass.h"

#include <iostream>

ConcreteClass::ConcreteClass()
{
    // ...
}

ConcreteClass::~ConcreteClass()
{
    // ...
}

void ConcreteClass::action1(int value)
{
    std::cout << "ConcreteClass::action1, x = " << value << std::endl;
}

void ConcreteClass::action2()
{
    std::cout << "ConcreteClass::action2" << std::endl;
}
