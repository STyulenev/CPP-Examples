#pragma once

#include <iostream>

/*
 * Примеры переопределения методов
 *
 * При наследовании в C++ класс-потомок наследует все методы базового класса, кроме конструкторов, деструктора и операции присваивания.
 *
 * Если в классе-родителе и в его классах-потомках встречаются методы с одинаковым именем, то для объектов класса-потомка компилятор
 * будет использовать методы именно класса-потомка.
 *
 * Однако есть исключение: если в базовом классе метод определён как виртуальный, то метод, определённый в производном классе с тем
 * же именем и набором параметров, автоматически становится виртуальным и наследуется.
 *
 */
namespace Example1 {

class Base
{
public:
    virtual ~Base() = default;

    virtual void method() = 0;
    virtual void method(int num) = 0;
    virtual void method(std:: string str) = 0;

    // Ошибка, методы не могут отличаться только возвращаемым типом
    // virtual int method() = 0;

    virtual void method1() {
        std::cout << "void Base::method1()" << std::endl;
    }

    void method2() {
        std::cout << "void Base::method2()" << std::endl;
    }

    void method3() {
        std::cout << "void Base::method3()" << std::endl;
    }
};

class Derived1 : public Base
{
public:
    virtual void method() {
        std::cout << "void Derived1::method()" << std::endl;
    }

    virtual void method([[maybe_unused]] int num) {
        std::cout << "void Derived1::method(int num)" << std::endl;
    }

    // Нет virtual
    void method([[maybe_unused]] std::string str) /* override */ {
        std::cout << "void Derived1::method(std::string str)" << std::endl;
    }

    virtual void method1() {
        std::cout << "void Derived1::method1()" << std::endl;
    }

    void method2() {
        std::cout << "void Derived1::method2()" << std::endl;
    }

    virtual void method3() {
        std::cout << "void Derived1::method3()" << std::endl;
    }

};

class Derived2 : public Derived1
{
public:
    virtual void method() {
        std::cout << "void Derived2::method()" << std::endl;
    }

    virtual void method([[maybe_unused]] int num) {
        std::cout << "void Derived2::method(int num)" << std::endl;
    }

    virtual void method([[maybe_unused]] std::string str) {
        std::cout << "void Derived2::method(std::string str)" << std::endl;
    }

    // Отсутствует virtual void method1() ...

    void method2() {
        std::cout << "void Derived2::method2()" << std::endl;
    }

    virtual void method3() {
        std::cout << "void Derived2::method3()" << std::endl;
    }

};

// Указатель на Base, объект Derived1
void test1()
{
    std::cout << "test1()\n" << std::endl;

    Base* d = new Derived1();

    d->method();      // Будет вызван void Derived1::method()
    d->method(5);     // Будет вызван void Derived1::method(int num)
    d->method("str"); // Будет вызван void Derived1::method(std::string str)

    d->method1(); // Будет вызван void Derived1::method1()
    d->method2(); // Будет вызван void Base::method2()
    d->method3(); // Будет вызван void Base::method3()

    delete d;
}

// Указатель на Base, объект Derived2
void test2()
{
    std::cout << "\ntest2()\n" << std::endl;

    Base* d = new Derived2();

    d->method();      // Будет вызван void Derived2::method()
    d->method(5);     // Будет вызван void Derived2::method(int num)
    d->method("str"); // Будет вызван void Derived2::method(std::string str)

    d->method1(); // Будет вызван void Derived1::method1()
    d->method2(); // Будет вызван void Base::method2()
    d->method3(); // Будет вызван void Base::method3()

    delete d;
}

// Указатель на Derived2, объект Derived2
void test3()
{
    std::cout << "\ntest3()\n" << std::endl;

    Derived2* d = new Derived2();

    d->method();      // Будет вызван void Derived2::method()
    d->method(5);     // Будет вызван void Derived2::method(int num)
    d->method("str"); // Будет вызван void Derived2::method(std::string str)

    d->method1(); // Будет вызван void Derived1::method1()
    d->method2(); // Будет вызван void Derived2::method2()
    d->method3(); // Будет вызван void Derived2::method3()

    delete d;
}

// Указатель на Derived1, объект Derived2
void test4()
{
    std::cout << "\ntest4()\n" << std::endl;

    Derived1* d = new Derived2();

    d->method();      // Будет вызван void Derived2::method()
    d->method(5);     // Будет вызван void Derived2::method(int num)
    d->method("str"); // Будет вызван void Derived2::method(std::string str)

    d->method1(); // Будет вызван void Derived1::method1()
    d->method2(); // Будет вызван void Derived1::method2()
    d->method3(); // Будет вызван void Derived2::method3()

    delete d;
}

// Указатель на Derived1, объект Derived1
void test5()
{
    std::cout << "\ntest4()\n" << std::endl;

    Derived1* d = new Derived1();

    d->method();      // Будет вызван void Derived1::method()
    d->method(5);     // Будет вызван void Derived1::method(int num)
    d->method("str"); // Будет вызван void Derived1::method(std::string str)

    d->method1(); // Будет вызван void Derived1::method1()
    d->method2(); // Будет вызван void Derived1::method2()
    d->method3(); // Будет вызван void Derived1::method3()

    delete d;
}

} // namespace Example1
