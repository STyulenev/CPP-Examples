#include "ConcreteStateA.h"
#include "ConcreteStateB.h"

#include "Context.h"

#include <iostream>

void ConcreteStateA::handle1()
{
    std::cout << "ConcreteStateA: handles1 running..." << std::endl;
    std::cout << "ConcreteStateA: change state" << std::endl;

    this->context_->transitionTo(new ConcreteStateB());
}

void ConcreteStateA::handle2()
{
    std::cout << "ConcreteStateA handles2 running..." << std::endl;
}
