#include "Component1.h"

#include <iostream>

void Component1::doA()
{
    std::cout << "Component 1 does task A." << std::endl;
    this->mediator_->notify(this, "A");
}

void Component1::doB()
{
    std::cout << "Component 1 does B." << std::endl;
    this->mediator_->notify(this, "B");
}
