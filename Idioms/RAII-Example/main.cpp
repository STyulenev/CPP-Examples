#include <iostream>

#include "RAIIWrapper.h"
#include "SomeClass.h"

int main()
{
    {
        SomeClass* someClass = new SomeClass();
        someClass->run();
    } // Утечка памяти

    std::cout << std::endl;

    {
        RAIIWrapper<SomeClass> someClass;
        someClass.get()->run();
    } // Нет утечки

    return 0;
}
