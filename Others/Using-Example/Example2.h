#pragma once

#include <iostream>

/*
 * Пример использования using в C++ при наследовании:
 * — переопределение видимости методов родительского класса в дочернем.
 */
namespace Example2 {

class Base
{
protected:
    void f(char) {
        std::cout << "Base::f(char)" << std::endl;
    }

    void g(char) {
        std::cout << "Base::g(char)" << std::endl;
    }
};

class Derived : Base
{
public:
    using Base::f;    // Base::f(char) теперь доступна как Derived::f(char)
    using Base::g;    // Base::g(char) теперь доступна как Derived::g(char)

    void f(int) {
        std::cout << "Derived::f(int)" << std::endl;
        f('c');     // Вызывает Base::f(char) вместо рекурсии
    }

    void g(int) {
        std::cout << "Derived::g(int" << std::endl;
        g('c');     // Вызывает Base::g(char) вместо рекурсии
    }
};

void test5()
{
    Derived d;
    d.f(1);
    d.f('c');
    d.g(1);
    d.g('a');
}

} // namespace Example2
