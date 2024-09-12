#include "Component2.h"

#include <iostream>

void Component2::doC()
{
    std::cout << "Component 2 does task C." << std::endl;
    this->mediator_->notify(this, "C");
}

void Component2::doD()
{
    std::cout << "Component 2 does task D." << std::endl;
    this->mediator_->notify(this, "D");
}
