#include "SomeClass.h"

#include <iostream>

SomeClass::SomeClass()
{
    std::cout << "Create SomeClass" << std::endl;
}

SomeClass::~SomeClass()
{
    std::cout << "Destruct SomeClass" << std::endl;
}

void SomeClass::run()
{
    std::cout << "Run SomeClass" << std::endl;
}
