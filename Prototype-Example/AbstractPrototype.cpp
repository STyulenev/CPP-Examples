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

    std::cout << "Call Method from " << prototypeName_ << " with field : " << prototypeField << std::endl;
}
