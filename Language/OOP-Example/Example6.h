#pragma once

#include <iostream>

/*
 * Использование using для использования метода базового класса:
 * - разрешение на вызов protected метода базового класса через наследника;
 * -
 */
namespace Example6 {

class Base
{
public:
    Base() {
        //std::cout << "Base::Base()" << std::endl;
    }

    virtual ~Base() {
        //std::cout << "Base::~Base()" << std::endl;
    }

    virtual void method() {
        std::cout << "Base::method" << std::endl;
    }

    virtual void method2() {
        std::cout << "Base::method2" << std::endl;
    }

protected:
    void method3() {
        std::cout << "Base::method3" << std::endl;
    }

};

class Derived : public Base
{
public:
    Derived() {
        //std::cout << "Derived::Derived()" << std::endl;
    }

    ~Derived() {
        //std::cout << "Derived::~Derived()" << std::endl;
    }

    virtual void method() {
        std::cout << "Derived::method" << std::endl;
        //Base::method();
    }

    // Можно убрать
    using Base::method2;

    void method3() {
        std::cout << "Derived::method3" << std::endl;
    }

};

class Derived2 : public Derived
{
public:
    Derived2() {
        //std::cout << "Derived2::Derived2()" << std::endl;
    }

    ~Derived2() {
        //std::cout << "Derived2::~Derived2()" << std::endl;
    }

    using Base::method;
    using Base::method2;
    using Base::method3;

};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Derived* d = new Derived();
    d->method();  // Derived::method
    d->method2(); // Base::method2
    d->method3(); // Base::method3

    delete d;
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* b = new Derived();
    b->method();  // Derived::method
    b->method2(); // Base::method2
    //b->method3(); // Base::method3 (без protected)

    delete b;
}

void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Base* b = new Derived2();
    b->method();  // Derived::method
    b->method2(); // Base::method2
    //b->method3(); // Base::method3 (без protected)

    delete b;
}

void test4()
{
    std::cout << "\ntest4()\n" << std::endl;

    Derived2* d = new Derived2();
    d->method();  // Derived::method
    d->method2(); // Base::method2
    d->method3(); // Base::method3

    delete d;
}

} // namespace Example6
