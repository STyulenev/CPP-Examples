#pragma once

#include <iostream>

/*
 * Объединение структур и классов
 *
 * Объединение может содержать вложенные структуры или классы.
 *
 */
namespace Example4
{

struct A
{
    int a;
};

struct B
{
    char b;
};

union MixedUnion
{
    A objA;
    B objB;
};

void test()
{
    MixedUnion mu;
    mu.objA.a = 100;
    std::cout << "Value of A's field: " << mu.objA.a << std::endl;

    mu.objB.b = 'X';
    std::cout << "Value of B's field: " << static_cast<int>(mu.objB.b) << std::endl;
}

} // namespace Example4
