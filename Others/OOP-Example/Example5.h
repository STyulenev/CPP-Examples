#pragma once

#include <iostream>

/*
 * Наследование и перегрузка
 */
namespace Example5 {

class Base
{
public:
    Base() {
        //std::cout << "Base::Base(int a)" << std::endl;
    }

    virtual ~Base() {
        //std::cout << "Base::~Base()" << std::endl;
    }

    virtual void method(int i = 10) {
        std::cout << "Base::method" << std::endl;
    }

    virtual void method2(int i = 10) {
        std::cout << "Base::method2" << std::endl;
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

    virtual void method2(std::string m = "") {
        std::cout << "Derived::method2" << std::endl;
    }

    // call to member function ambiguous
    /*virtual void method2(int i = 10) override {
        std::cout << "Base::method2" << std::endl;
    }*/

};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Base b;
    b.method();   // "Base::method"
    b.method(4);  // "Base::method"
    b.method2();  // "Base::method2"
    b.method2(4); // "Base::method2"

    Derived d;
    d.method();       // "Derived::method"
    d.method2();      // "Derived::method2"
    d.method2("eee"); // "Derived::method2"
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* b = new Derived();
    b->method();   // "Base::method"
    b->method(4);  // "Base::method"
    b->method2();  // "Base::method2"
    b->method2(4); // "Base::method2"
    //b->method2("eee"); // Ошибка

    delete b;
}

void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Derived* d = new Derived();
    d->method();       // Derived::method
    //d->method(4);    // Ошибка
    d->method2();      // Derived::method2
    //d->method2(4);   // Ошибка
    d->method2("eee"); // Derived::method2

    delete d;
}

} // namespace Example5
