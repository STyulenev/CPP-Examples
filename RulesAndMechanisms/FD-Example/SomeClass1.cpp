#include "SomeClass1.h"
#include "SomeClass2.h"

#include <iostream>

SomeClass1::SomeClass1()
{
    // ...
}

SomeClass1::~SomeClass1()
{
    // ...
}

void SomeClass1::setSomeClass(SomeClass2* someClass)
{
    m_someClass = someClass;
}

void SomeClass1::print()
{
    std::cout << "SomeClass1::print()";
}

void SomeClass1::printSC1()
{
    std::cout << "someClass1 ... ";

    if (m_someClass)
        m_someClass->print();

    std::cout << " ..." << std::endl;
}
