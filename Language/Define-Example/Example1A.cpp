#include "Example1.h"

#include <iostream>

namespace Example1 {

MyClass1::MyClass1()
{
    std::cout << "MyClass1::MyClass1()" << std::endl;
}

void MyClass1::doTask()
{
    std::cout << "void MyClass1::doTask()" << std::endl;
}

} // namespace Example1
