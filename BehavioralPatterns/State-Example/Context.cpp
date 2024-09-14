#include "Context.h"

#include <iostream>
#include <typeinfo>

Context::Context(AbstractState* state) :
    state_(nullptr)
{
    this->transitionTo(state);
}

Context::~Context()
{
    delete state_;
}

void Context::transitionTo(AbstractState* state)
{
    std::cout << "Context: Transition to " << typeid(*state).name() << std::endl;

    if (this->state_ != nullptr)
        delete this->state_;

    this->state_ = state;
    this->state_->setContext(this);
}

void Context::request1()
{
    this->state_->handle1();
}

void Context::request2()
{
    this->state_->handle2();
}
