#pragma once

#include <iostream>

/*
 * Использование с разными аргументами со значениями по умолчанию при наследовании.
 *
 * Аргумент по умолчанию будет зависеть от типа указателя:
 * - Derived* d = new Derived(); - будет использовать аргумент из переопределенного метода в Derived
 * - Base* b = new Derived();    - будет использовать аргумент из метода в Base
 *
 * Типы аргументов по умолчанию могут изменятся. Будут вызываться методы в зависимости от типа указателя.
 */

namespace Example11 {

class Base
{
public:
    Base() { std::cout << "Base::Base()" << std::endl; }

    ~Base() { std::cout << "Base::~Base()" << std::endl; }

    virtual void method1(int a = 1)
    {
        std::cout << "Base::method2(), a = " << a << std::endl;
    }

    virtual void method2(int a = 1)
    {
        std::cout << "Base::method2(), a = " << a << std::endl;
    }

};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived::Derived()" << std::endl; }
    ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }

    virtual void method1(int a = 2) override
    {
        std::cout << "Derived::method1(), a = " << a << std::endl;
    }

    virtual void method2(std::string a = "aaaa")
    {
        std::cout << "Derived::method2(), a = " << a << std::endl;
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Derived d;
    d.method1(); // Derived::method((), a = 2
    d.method2(); // Derived::method((), a = aaa
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* b = new Derived();
    b->method1(); // Derived::method(), a = 1
    b->method2(); // Derived::method(), a = 1

    delete b;
}

void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Base* b = new Derived();
    b->method1(5); // Derived::method(), a = 5
    b->method2(5); // Derived::method(), a = 5

    delete b;
}

void test4()
{
    std::cout << "\ntest4()\n" << std::endl;

    Derived* d = new Derived();
    d->method1(5); // Derived::method(), a = 5
    //d->method2(5); // Ошибка
    d->method2("bbb"); // Base::method2(), a = bbb

    delete d;
}

} // namespace Example11
