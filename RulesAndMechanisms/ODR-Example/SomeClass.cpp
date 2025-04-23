#include "SomeClass.h"

#include <iostream>

// Нельзя, ошибка multiple definition of `someFunction()';
/*void someFunction()
{
    std::cout << "someFunction()" << std::endl;
}*/

// Так можно
namespace {

void someFunction()
{
    std::cout << "::someFunction()" << std::endl;
}

}

SomeClass::SomeClass()
{

}

void SomeClass::someFunction()
{
    std::cout << "SomeClass::someFunction()" << std::endl;

    ::someFunction();
}
