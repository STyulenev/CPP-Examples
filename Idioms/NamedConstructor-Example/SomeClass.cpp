#include "SomeClass.h"

#include <iostream>

SomeClass SomeClass::createSomeClassWithStatus_1()
{
    return SomeClass(1);
}

SomeClass SomeClass::createSomeClassWithStatus_2()
{
    return SomeClass(2);
}

SomeClass SomeClass::createSomeClassWithStatus_3()
{
    return SomeClass(3);
}

void SomeClass::print()
{
    std::cout << "SomeClass::print() status = " << status << std::endl;
}

SomeClass::~SomeClass()
{
    // ...
}

SomeClass::SomeClass() :
    status(0)
{

}

SomeClass::SomeClass(int status) :
    status(status)
{
    // ...
}
