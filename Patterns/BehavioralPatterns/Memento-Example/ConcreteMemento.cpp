#include "ConcreteMemento.h"

ConcreteMemento::ConcreteMemento(std::string state) :
    state_(state)
{
    this->state_ = state;
    this->date_ = "current date/time";
}

std::string ConcreteMemento::state() const
{
    return this->state_;
}

std::string ConcreteMemento::getName() const
{
    return this->date_ + " (" + this->state_ + "...)";
}

std::string ConcreteMemento::date() const
{
    return this->date_;
}
