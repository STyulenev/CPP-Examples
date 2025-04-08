#pragma once

#include <iostream>

/*
 * Пример private наследование
 *
 * Private наследование в C++ означает, что все унаследованные данные базового класса становятся приватными в производном классе.
 * При таком наследовании данные базового класса доступны из методов производного класса, но недоступны извне, то есть они становятся private.
 *
 */
namespace Example2 {

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

private:
    virtual void method1() {
        std::cout << "Base::method1()" << std::endl;
    }

};

class Derived : private Base
{
public:
    Derived() : Base(5) {
        std::cout << "Derived::Derived()" << std::endl;
    }

    virtual ~Derived() {
        std::cout << "Derived::~Derived()" << std::endl;
    }

    virtual void method() {
        // Base::method(); // Работает

        std::cout << "Derived::method()" << std::endl;
    }

    virtual void method1() {
        //Base::method1(); // Ошибка, метод недоступен

        std::cout << "Derived::method1()" << std::endl;
    }
};

void test1()
{
    std::cout << "test1()\n" << std::endl;

    Base* b = new Base();
    b->method();
    // b->method1(); // Ошибка, метод недоступен

    delete b;
}

void test2()
{
    std::cout << "test2()\n" << std::endl;

    // Base* d = new Derived(); // Ошибка
    Derived* d = new Derived();
    // Base* b = dynamic_cast<Base*>(d); // Ошибка
    d->method();
    d->method1();

    delete d;
}

} // namespace Example2
