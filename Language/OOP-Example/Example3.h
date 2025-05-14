#pragma once

#include <iostream>

/*
 * Пример protected наследование
 *
 * Смысл protected-наследования в том, что если у производного класса будут свои классы-наследники, то в этих классах-наследниках
 * также можно обращаться к подобным членам базового класса.
 *
 */
namespace Example3 {

class Base
{
public:
    Base() {
        std::cout << "Base::Base()" << std::endl;
    }

    Base(int a) {
        std::cout << "Base::Base(int a)" << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base::~Base()" << std::endl;
    }

    virtual void method() {
        std::cout << "Base::method()" << std::endl;
    }

protected:
    virtual void method1() {
        std::cout << "Base::method1()" << std::endl;
    }

};

class Derived : protected Base
{
public:
    Derived() : Base(5) {
        std::cout << "Derived::Derived()" << std::endl;
    }

    virtual ~Derived() {
        std::cout << "Derived::~Derived()" << std::endl;
    }

    virtual void method() {
        Base::method(); // Работает

        std::cout << "Derived::method()" << std::endl;
    }

    virtual void method1() {
        Base::method1(); // Работает

        std::cout << "Derived::method1()" << std::endl;
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Base* b = new Base();
    b->method();
    //b->method1(); // Ошибка, метод недоступен

    delete b;
}

void test2()
{
    std::cout << "test2()\n" << std::endl;

    //Base* d = new Derived(); // Ошибка
    Derived* d = new Derived();
    // Base* b = dynamic_cast<Base*>(d); // Ошибка
    d->method();
    d->method1();

    delete d;
}

} // namespace Example3
