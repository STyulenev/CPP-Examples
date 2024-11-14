#include "SomeClass.h"

#include <iostream>

SomeClass::SomeClass() :
    field(5)
{
    // ...
}

SomeClass::SomeClass(const int field) :
    field(field)
{
    // ...
}

SomeClass::~SomeClass()
{
    std::cout << "-----deleted-----" << std::endl;
}

int SomeClass::getField() const
{
    return field;
}

void SomeClass::setField(const int field)
{
    this->field = field;
}

bool SomeClass::operator==(const SomeClass& rhs)
{
    return (field == rhs.field);
}
