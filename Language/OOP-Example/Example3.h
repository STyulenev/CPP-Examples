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

class Derived1 : protected Base
{
public:
    Derived1() : Base(5) {
        std::cout << "Derived1::Derived1()" << std::endl;
    }

    virtual ~Derived1() {
        std::cout << "Derived1::~Derived1()" << std::endl;
    }

    virtual void method() {
        Base::method(); // Работает

        std::cout << "Derived1::method()" << std::endl;
    }

    virtual void method1() {
        Base::method1(); // Работает

        std::cout << "Derived1::method1()" << std::endl;
    }
};

class Derived2 : public Derived1
{
public:
    Derived2() {
        std::cout << "Derived2::Derived2()" << std::endl;
    }

    virtual ~Derived2() {
        std::cout << "Derived2::~Derived2()" << std::endl;
    }

    virtual void method() {
        Base::method(); // Работает
        Derived1::method(); // Работает

        std::cout << "Derived2::method()" << std::endl;
    }

    virtual void method1() {
        Base::method1(); // Работает
        Derived1::method1(); // Работает

        std::cout << "Derived2::method1()" << std::endl;
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

    //Base* d = new Derived1(); // Ошибка
    Derived1* d = new Derived1();
    // Base* b = dynamic_cast<Base*>(d); // Ошибка
    d->method();
    d->method1();

    delete d;
}

void test3()
{
    std::cout << "test3()\n" << std::endl;

    //Base* d = new Derived2(); // Ошибка
    Derived1* d = new Derived2();
    // Base* b = dynamic_cast<Base*>(d); // Ошибка
    d->method();
    d->method1();

    delete d;
}

} // namespace Example3
