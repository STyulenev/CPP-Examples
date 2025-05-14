#include "Example1.h"

#include <iostream>

static int num = 0;

static void internalFunction()
{
    std::cout << "Example1.cpp -> internalFunction()" << std::endl;
}

// или через анонимное пространство имён
/*namespace {

void internalFunction()
{
    std::cout << "Example1.cpp -> internalFunction()" << std::endl;
}

}*/

namespace Example1 {

void test1()
{
    internalFunction();
}

void test2()
{
    std::cout << "Example1.cpp -> num = " << num << std::endl;
}

} // namespace Example1
