#include "Example3.h"

#include <iostream>

namespace Example3 {

int SomeClass::_num2 = 0;

void SomeClass::print()
{
    std::cout << "static void Example3::print()" << std::endl;
}

void SomeClass::num1()
{
    std::cout << "static void Example3::add() num1 = " << _num1 << std::endl;
}

void SomeClass::num2()
{
    _num2++;
    std::cout << "static void Example3::add() num1 = " << _num2 << std::endl;
}

void test4()
{
    static int data = 0;
    std::cout << "static void Example3::test4() data = " << data++ << std::endl;
}

} // namespace Example3
