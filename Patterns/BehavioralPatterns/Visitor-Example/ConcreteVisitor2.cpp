#include "ConcreteVisitor2.h"

#include <iostream>

#include "ConcreteComponentA.h"
#include "ConcreteComponentB.h"

void ConcreteVisitor2::visitConcreteComponentA(const ConcreteComponentA* element) const
{
    std::cout << element->someActionConcreteComponentA() << " + ConcreteVisitor2" << std::endl;
}

void ConcreteVisitor2::visitConcreteComponentB(const ConcreteComponentB* element) const
{
    std::cout << element->someActionConcreteComponentB() << " + ConcreteVisitor2" << std::endl;
}
