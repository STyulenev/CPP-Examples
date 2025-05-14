#pragma once

#include <iostream>

/*
 * Пример inline:
 * - С шаблонами;
 * - С virtual.
 */

namespace Example2 {

class MyClass
{
public:
    // Встроенная шаблонная функция
    template <typename Type>
    inline void tempfunc1() {
        std::cout << "inline void tempfunc1()" << std::endl;
    }

    template <typename Type>
    void tempfunc2();

};

// Реализация вне класса
template<typename Type>
inline void MyClass::tempfunc2()
{
    std::cout << "inline void tempfunc2()" << std::endl;
}

class IBase
{
public:
    virtual ~IBase() = default;
    virtual inline void func() = 0;

};

class Derived1 : public IBase
{
public:
    virtual ~Derived1() = default;
    virtual inline void func() {
        std::cout << "virtual inline void Derived1::func()" << std::endl;
    }

};

class Derived2 : public Derived1
{
public:
    virtual inline void func() {
        std::cout << "virtual inline void Derived2::func()" << std::endl;
    }

};

void test1()
{
    std::cout << "\ntest1()\n\n";

    MyClass{}.tempfunc1<void>();
}

void test2()
{
    std::cout << "\ntest2()\n\n";

    MyClass{}.tempfunc2<void>();
}

void test3()
{
    std::cout << "\ntest3()\n\n";

    IBase* b = new Derived1();
    b->func();
    delete b;
}

void test4()
{
    std::cout << "\ntest4()\n\n";

    Derived1* d = new Derived1();
    d->func();
    delete d;
}

void test5()
{
    std::cout << "\ntest5()\n\n";

    Derived2* d = new Derived2();
    d->func();
    delete d;
}

} // namespace Example2
