#include "Invoker.h"

#include <iostream>

Invoker::Invoker()
{

}

Invoker::~Invoker()
{
    delete onStart_;
    delete onFinish_;
}

void Invoker::setOnStart(CommandInterface* command)
{
    this->onStart_ = command;
}

void Invoker::setOnFinish(CommandInterface* command)
{
    this->onFinish_ = command;
}

void Invoker::someAction()
{
    std::cout << "Invoker: Start process..." << std::endl;

    if (this->onStart_) {
        this->onStart_->execute();
    }

    std::cout << "Invoker: ...loading..." << std::endl;
    std::cout << "Invoker: process before finish..." << std::endl;

    if (this->onFinish_) {
        this->onFinish_->execute();
    }
}
