#include "AbstractHandler.h"

#include <iostream>

AbstractHandler::AbstractHandler() :
    nextHandler_(nullptr)
{
    // ...
}

AbstractHandler::~AbstractHandler()
{
    // ...
}

HandlerInterface* AbstractHandler::next(HandlerInterface* handler)
{
    this->nextHandler_ = handler;

    return handler;
}

std::string AbstractHandler::someAction(std::string request)
{
    std::cout << " ... searching ..." << std::endl;

    if (this->nextHandler_) {
        return this->nextHandler_->someAction(request);
    }

    return {};
}
