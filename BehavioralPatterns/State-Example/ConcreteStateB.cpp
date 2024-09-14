#include "ConcreteStateB.h"
#include "ConcreteStateA.h"

#include "Context.h"

#include <iostream>

void ConcreteStateB::handle1()
{
    std::cout << "ConcreteStateB: handles1 running..." << std::endl;
}

void ConcreteStateB::handle2()
{
    std::cout << "ConcreteStateB: handles2 running..." << std::endl;
    std::cout << "ConcreteStateB: change state" << std::endl;

    this->context_->transitionTo(new ConcreteStateA());
}
