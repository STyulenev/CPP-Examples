#pragma once

#include <iostream>

/*
 * Невиртуальный деструктор
 *
 * 1. Если у объекта совпадает тип указателя и тип объекта (Derived1* d = new Derived1()), то создание и удаление отработает в
 * базовом классе и наследнике.
 *
 * 2. Если у объекта не совпадает тип указателя и тип объекта (Base* b = new Derived1(), Base* b = new Derived2()), то создание
 * отработает во всех классах, а удаление нет. Это будет происходить в зависимости от типа объекта. Если тип указателя Base* и
 * объект типа Derived2*, то сработает только деструкор Base. Если тип указателя Derived1* и объект типа Derived2, то сработают деструкторы
 * Base и Derived1. Если тип указателя Derived2* и объект типа Derived2*, то все деструкторы.
 *
 * Базовый класс обязательно следует помечать как virtual для корректного освобождения ресурсов, а деструкторы наследников
 * можно помечать как virtual или как override (одновременно не работает).
 */
namespace Example8 {

class Base
{
public:
    Base() {
        std::cout << "Base::Base()" << std::endl;
    }

    /* virtual */ ~Base()  {
        std::cout << "Base::~Base()" << std::endl;
    }

};

class Derived1 : public Base
{
public:
    Derived1() {
        std::cout << "Derived1::Derived1()" << std::endl;
    }

    /* virtual */ ~Derived1() /* override */ {
        std::cout << "Derived1::~Derived1()" << std::endl;
    }
};

class Derived2 : public Derived1
{
public:
    Derived2() {
        std::cout << "Derived2::Derived2()" << std::endl;
    }

    /* virtual */ ~Derived2() /* override */ {
        std::cout << "Derived2::~Derived2()" << std::endl;
    }
};

void test1()
{
    std::cout << "\ntest1()\n" << std::endl;

    Derived1* d = new Derived1();

    delete d;

    /*
     * Base::Base()
     * Derived1::Derived1()
     * Derived1::~Derived1()
     * Base::~Base()
     */
}

void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* b = new Derived1();

    delete b;

    /*
     * Base::Base()
     * Derived1::Derived1()
     * Base::~Base()
     */
}

void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Derived1* d = new Derived2();

    delete d;

    /*
     * Base::Base()
     * Derived1::Derived1()
     * Derived2::Derived2()
     * Derived1::~Derived1()
     * Base::~Base()
     */
}

void test4()
{
    std::cout << "\ntest4()\n" << std::endl;

    Base* b = new Derived2();

    delete b;

    /*
     * Base::Base()
     * Derived1::Derived1()
     * Derived2::Derived2()
     * Derived1::~Derived1()
     * Base::~Base()
     */
}

} // namespace Example8
