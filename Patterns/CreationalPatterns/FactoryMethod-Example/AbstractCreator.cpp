#include "AbstractCreator.h"

Creator::Creator()
{
    // ...
}

Creator::~Creator()
{
    // ...
}

std::string Creator::someOperation() const
{
    AbstractProduct* product = this->factoryMethod();
    std::string result = "Creator: The same creator's code has just worked with " + product->operation();
    delete product;
    return result;
}
