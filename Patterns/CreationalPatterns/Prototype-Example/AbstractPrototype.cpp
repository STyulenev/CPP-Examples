#include "AbstractPrototype.h"

#include <iostream>

AbstractPrototype::AbstractPrototype()
{
    // ...
}

AbstractPrototype::AbstractPrototype(std::string prototypeName) :
    prototypeName_(prototypeName)
{
    // ...
}

AbstractPrototype::~AbstractPrototype()
{
    // ...
}

void AbstractPrototype::method(float prototypeField)
{
    this->prototypeField_ = prototypeField;

    std::cout << "Type: " << prototypeName_ << "data: " << prototypeField << std::endl;
}
