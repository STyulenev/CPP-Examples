#pragma once

#include <iostream>

/*
 * Скрытие имени в классах и наследовании:
 */

namespace Example2
{

class Base
{
public:
    void foo(int x) { std::cout << "Base::foo(int x) = " << x << "\n"; } // первая перегрузка
    void foo(double x) { std::cout << "Base::foo(double x) = " << x << "\n"; } // вторая перегрузка
    //void foo(std::string x) { std::cout << "Base::foo(std::string x) = " << x << "\n"; } // тест перекрытия
};

class Derived : public Base
{
public:
    //using Base::foo; // Чтобы открыть все перегрузки Base
    void foo(std::string x) { std::cout << "Derived::foo(std::string x) = " << x << "\n"; } // третья перегрузка — скрывает обе из Base!
};

void test()
{
    {
        Base b;
        b.foo(42);       // Нет ошибки
        b.foo(3.14);     // Нет ошибки
        //b.foo("test"); // Ошибка, перекрывающая перегрузка с типом std::string есть только у наследника
    }

    {
        Derived d;
        //d.foo(42);   // Ошибка: нет подходящей функции в Derived
        //d.foo(3.14); // Ошибка: нет подходящей функции в Derived
        d.foo("test"); // Нет ошибки
    }
}

} // namespace Example2
