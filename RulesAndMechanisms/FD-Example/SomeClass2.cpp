#include "SomeClass1.h"
#include "SomeClass2.h"

#include <iostream>

SomeClass2::SomeClass2()
{
    // ...
}

SomeClass2::~SomeClass2()
{
    // ...
}

void SomeClass2::setSomeClass(SomeClass1* someClass)
{
    m_someClass = someClass;
}

void SomeClass2::print()
{
    std::cout << "SomeClass2::print()";
}

void SomeClass2::printSC2()
{
    std::cout << "someClass2 ... ";

    if (m_someClass)
        m_someClass->print();

    std::cout << " ..." << std::endl;
}
