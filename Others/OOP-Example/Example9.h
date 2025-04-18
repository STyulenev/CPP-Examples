#pragma once

#include <iostream>

/*
 * Вызовы виртуальных методов при удалении объекта
 * Вызовы виртуальных методов через невиртуальный метод
 */
namespace Example9 {

class Base
{
private:
    virtual void method() {
        std::cout << "Base::method()" << std::endl;
    }
public:
    virtual ~Base() {
        method();
    }

    void baseMethod() {
        method();
    }
};

class Derived : public Base
{
private:
    void method() {
        std::cout << "Derived::method()" << std::endl;
    }
public:
    ~Derived() {
        method();
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Base* b = new Derived();
    b->baseMethod();

    delete b;

    /*
     * Derived::method()
     * Derived::method()
     * Base::method()
    */
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Derived* d = new Derived();
    d->baseMethod();

    delete d;

    /*
     * Derived::method()
     * Derived::method()
     * Base::method()
    */
}

} // namespace Example9
