#include "Example1.h"

#include "Example0.h"

int num = 2;

extern void externalFunction()
{
    std::cout << "Example1.cpp -> externalFunction()" << std::endl;
}

namespace Example1 {

void test1()
{
    std::cout << "\nExample1::test1()\n";

    externalFunction();
}

void test2()
{
    std::cout << "\nExample1::test2()\n";

    std::cout << "num = " << num << std::endl;
}

void test3()
{
    // Здесь компилятором создаётся функция printType с типом int
    printType<int>();
}

} // namespace Example1
