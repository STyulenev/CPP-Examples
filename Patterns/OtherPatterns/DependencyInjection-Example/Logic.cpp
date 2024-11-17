#include "Logic.h"

#include <iostream>

Logic::Logic()
{
    // ...
}

Logic::~Logic()
{
    // ...
}

ConcreteLogic1::ConcreteLogic1()
{
    // ...
}

ConcreteLogic1::~ConcreteLogic1()
{
    // ...
}

void ConcreteLogic1::someAction()
{
    std::cout << "ConcreteLogic1::someAction()" << std::endl;
}

ConcreteLogic2::ConcreteLogic2()
{
    // ...
}

ConcreteLogic2::~ConcreteLogic2()
{
    // ...
}

void ConcreteLogic2::someAction()
{
    std::cout << "ConcreteLogic2::someAction()" << std::endl;
}
