#include "AbstractClass.h"

#include <iostream>

void AbstractClass::TemplateMethod() const
{
    this->baseAction1();
    this->baseAction2();
    this->baseAction3();

    // ...

    this->requiredAction1();
    this->requiredAction2();

    // ...

    this->optionalAction1();
    this->optionalAction2();
}

void AbstractClass::baseAction1() const
{
    std::cout << "  AbstractClass::baseAction1()" << std::endl;
}

void AbstractClass::baseAction2() const
{
    std::cout << "  AbstractClass::baseAction2()" << std::endl;
}

void AbstractClass::baseAction3() const
{
    std::cout << "  AbstractClass::baseAction3()" << std::endl;
}

void AbstractClass::optionalAction1() const
{
    // ...
}

void AbstractClass::optionalAction2() const
{
    // ...
}
