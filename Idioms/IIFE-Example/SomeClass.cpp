#include "SomeClass.h"

// IIFE для поля класса
SomeClass::SomeClass() :
    var([&] {
        int temp = 1;

        /* сложный код */

        temp *= 5;

        /* сложный код */

        return temp;
    }())
{
    // ...
}

SomeClass::~SomeClass()
{
    // ...
}

int SomeClass::getVar() const
{
    return var;
}
