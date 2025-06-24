#include "Example1.h"

#include <iostream>

namespace Example1 {

MyClass2::MyClass2()
{
    std::cout << "MyClass2::MyClass2()" << std::endl;
}

void MyClass2::doTask()
{
    std::cout << "void MyClass2::doTask()" << std::endl;
}

} // namespace Example1
