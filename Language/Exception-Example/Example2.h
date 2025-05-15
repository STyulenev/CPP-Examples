#pragma once

#include <iostream>

/*
 * Выброс исключения из деструктора.
 */

namespace Example2 {

class A
{
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    ~A() noexcept(false) {
        throw std::runtime_error("std::runtime_error in ~A()");

        std::cout << "~A()" << std::endl;
    }
};

void function()
{
    A a;

    throw std::runtime_error("std::runtime_error in ~A()");
}

/*
 * Если выбрасывается два исключения - через throw и из деструктора, то исключение из деструктора вызовет std::terminate
 * и std::runtime_error не будет обработано в catch.
 */
void test1()
{
    try {
        function();
    } catch (const std::exception& error) {
        std::cout << error.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

/*
 * При исключение из деструктора с меткой noexcept(false) объект удалится если стек успел "размататься".
 * Иначе произойдёт std::terminate.
 */
void test2()
{
    try {
        A a;
    } catch (const std::exception& error) {
        std::cout << error.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
}

} // namespace Example2
