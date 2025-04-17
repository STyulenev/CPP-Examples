#pragma once

#include <iostream>

/*
 * Примеры всевозможных перегрузок метода класса
 *
 */

namespace Example1 {

struct SomeClass {

    static const SomeClass createC() {
        return SomeClass();
    }

    static volatile SomeClass createV() {
        return SomeClass();
    }

    static const volatile SomeClass createCV() {
        return SomeClass();
    }

    // void foo() {} // Ошибка, уже есть "void foo() &"
    // void foo(int n = 0) & {} // Ошибка, уже есть "void foo() &"

    // void foo() & noexcept  // Ошибка, noexcept не перегружает функцию/метод
    // static void foo() & {} // Ошибка, static не перегружает функцию/метод
    // inline void foo() & {} // Ошибка, inline не перегружает функцию/метод

    void foo() & {
        std::cout << "void foo() &" << std::endl;
    }

    void foo() && {
        std::cout << "void foo() &&" << std::endl;
    }

    void foo() const & {
        std::cout << "void foo() const &" << std::endl;
    }

    void foo() const && {
        std::cout << "void foo() const &&" << std::endl;
    }

    void foo() volatile & {
        std::cout << "void foo() volatile &" << std::endl;
    }

    void foo() volatile && {
        std::cout << "void foo() volatile &&" << std::endl;
    }

    void foo() const volatile & {
        std::cout << "void foo() const volatile &" << std::endl;
    }

    void foo() const volatile && {
        std::cout << "void foo() const volatile &&" << std::endl;
    }

    void foo(int x) {
        std::cout << "void foo(int x)" << std::endl;
    }

    // void foo(const int x) {}          // Ошибка, это равнозначно void foo(int x) т.к. const удаляется из-за передачи по значению
    // void foo(const volatile int x) {} // Ошибка, это равнозначно т.к. const volatile удаляется из-за передачи по значению
    // long long int foo(int x) {}       // Ошибка, нельзя перегружать по возвращаемому значению

};

void test()
{
    {
        SomeClass lvalue;
        lvalue.foo();      // void foo() &
        SomeClass{}.foo(); // void foo() &&
    }

    std::cout << std::endl;

    {
        const SomeClass lvalue;
        lvalue.foo();               // void foo() const &
        SomeClass::createC().foo(); // void foo() const &&
    }

    std::cout << std::endl;

    {
        volatile SomeClass lvalue;
        lvalue.foo();               // void foo() volatile &
        SomeClass::createV().foo(); // void foo() volatile &&
    }

    std::cout << std::endl;

    {
        const volatile SomeClass lvalue;
        lvalue.foo();                // void foo() const volatile &
        SomeClass::createCV().foo(); // void foo() const volatile &&
    }

    std::cout << std::endl;

    {
        SomeClass* value = new SomeClass();
        value->foo(); // void foo() &
        delete value;
    }
}

} // namespace Example1
