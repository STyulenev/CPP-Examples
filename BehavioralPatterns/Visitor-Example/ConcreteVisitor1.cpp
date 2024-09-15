#include "ConcreteVisitor1.h"

#include <iostream>

#include "ConcreteComponentA.h"
#include "ConcreteComponentB.h"

void ConcreteVisitor1::visitConcreteComponentA(const ConcreteComponentA* element) const
{
    std::cout << element->someActionConcreteComponentA() << " + ConcreteVisitor1" << std::endl;
}

void ConcreteVisitor1::visitConcreteComponentB(const ConcreteComponentB* element) const
{
    std::cout << element->someActionConcreteComponentB() << " + ConcreteVisitor1" << std::endl;
}
