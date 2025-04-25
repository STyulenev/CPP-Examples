#include "Example2.h"

#include <iostream>

static int num = 2;

static void internalFunction()
{
    std::cout << "Example2.cpp -> internalFunction()" << std::endl;
}

namespace Example2 {

void test1()
{
    internalFunction();
}

void test2()
{
    std::cout << "Example1.cpp -> num = " << num << std::endl;
}

} // namespace Example2
