#pragma once

#include <iostream>

/*
 * Вызов виртуальных методов внутри класса
 */
namespace Example7 {

class Base
{
public:
    Base() {
        //std::cout << "Base::Base()" << std::endl;

        // Base::method(); // Ошибка
    }

    virtual ~Base() {
        //std::cout << "Base::~Base()" << std::endl;
    }

    virtual void method() = 0;

    virtual void method2() {
        std::cout << "Base::method2" << std::endl;
    }

};

class Derived : public Base
{
public:
    Derived() {
        //std::cout << "Derived::Derived()" << std::endl;

        // Base::method();  // Ошибка
        Derived::method();  // Работает
        Derived::method2(); // Работает
    }

    ~Derived() {
        //std::cout << "Derived::~Derived()" << std::endl;
    }

    virtual void method() {
        // Base::method(); // Ошибка
        std::cout << "Derived::method" << std::endl;
    }

    virtual void method2() {
        Base::method2(); // Работает
        std::cout << "Derived::method2" << std::endl;
    }

};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Derived* d = new Derived();
    d->method();
    d->method2();

    delete d;
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* b = new Derived();
    b->method();
    b->method2();

    delete b;
}

} // namespace Example7
