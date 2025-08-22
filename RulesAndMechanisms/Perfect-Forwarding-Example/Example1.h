#pragma once

#include <iostream>
#include <utility>

/*
 * Простой пример
 */

namespace Example1
{

void process(int& x)
{
    std::cout << "Lvalue: " << x << std::endl;
}

void process(int&& x)
{
    std::cout << "Rvalue: " << x << std::endl;
}

void process(const int& x)
{
    std::cout << "const Lvalue: " << x << std::endl;
}

void process(const int&& x)
{
    std::cout << "const Rvalue: " << x << std::endl;
}

template<typename T>
void forwarder(T&& arg)
{
    process(std::forward<T>(arg));
}

void test()
{
    int a = 42;
    const int c_a = 42;

    forwarder(a);   // Передаем lvalue
    forwarder(c_a); // Передаем const lvalue
    forwarder(100); // Передаем rvalue
    forwarder(static_cast<const int&&>(44)); // const Передаем rvalue
}

} // namespace Example1
