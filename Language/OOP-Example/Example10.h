#pragma once

#include <iostream>

/*
 * Использование объектов в стеке для проверки вызова функций
 *
 * Аналогично объектам в куче
 */
namespace Example10 {

class Base
{
public:
    virtual ~Base() {
        // ...
    }

    virtual void method() {
        std::cout << "Base::method()" << std::endl;
    }

    void method2() {
        std::cout << "Base::method2()" << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual ~Derived() {
        // ...
    }

    virtual void method() {
        std::cout << "Derived::method()" << std::endl;
    }

    void method2() {
        std::cout << "Derived::method2()" << std::endl;
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Base b = Derived();
    b.method();  // Будет вызван Base::method()
    b.method2(); // Будет вызван Base::method2()
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Derived d = Derived();
    d.method();  // Будет вызван Derived::method()
    d.method2(); // Будет вызван Derived::method2()
}

void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Base b = Derived();
    Derived* d = static_cast<Derived*>(&b);

    d->method();  // Будет вызван Derived::method()
    d->method2(); // Будет вызван Derived::method2()
}

} // namespace Example10
