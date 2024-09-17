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

void prindSizeNCapacity(const std::vector<SomeClass*>& v)
{
    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
}

void prindSizeNCapacity(const std::vector<SomeClass>& v)
{
    std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
}

void printVector(const std::vector<SomeClass*>& v)
{
    std::cout << "Print vector: ";

    for (auto el : v) {
        if (el)
            std::cout << el->getField() << " ";
    }

    std::cout << std::endl;
}
