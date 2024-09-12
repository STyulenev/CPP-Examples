#include "Receiver.h"

#include <iostream>

void Receiver::doSomething(const std::string& a)
{
    std::cout << "Receiver: Working on (" << a << ".)" << std::endl;
}

void Receiver::doSomethingElse(const std::string& b)
{
    std::cout << "Receiver: Also working on (" << b << ".)" << std::endl;
}
