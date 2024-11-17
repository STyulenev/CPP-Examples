#include "Originator.h"

#include "ConcreteMemento.h"

#include <iostream>

Originator::Originator(std::string state) :
    state_(state)
{
    std::cout << "Originator: initial state is: " << this->state_ << std::endl;
}

void Originator::update(const std::string &state)
{
    this->state_ = state;
}

MementoInterface *Originator::save()
{
    return new ConcreteMemento(this->state_);
}

void Originator::restore(MementoInterface* memento)
{
    this->state_ = memento->state();
    std::cout << "Originator: state has changed to: " << this->state_ << std::endl;
}
