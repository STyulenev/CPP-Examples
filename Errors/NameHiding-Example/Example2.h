#pragma once

#include <iostream>

/*
 * Скрытие имени в классах и наследовании
 */

namespace Example2_1
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

} // namespace Example2_1

namespace Example2_2
{

class Base
{
public:
    virtual void foo(int x) { std::cout << "Base::foo(int x) = " << x << "\n"; } // первая перегрузка
    virtual void foo(double x) { std::cout << "Base::foo(double x) = " << x << "\n"; } // вторая перегрузка
    virtual void foo(std::string x) { std::cout << "Base::foo(std::string x) = " << x << "\n"; } // тест перекрытия
};

class Derived : public Base
{
public:
    //using Base::foo; // Чтобы открыть все перегрузки Base
    virtual void foo(std::string x) { std::cout << "Derived::foo(std::string x) = " << x << "\n"; } // третья перегрузка — скрывает обе из Base!
};

void test()
{
    {
        Base b = Base();
        b.foo(42);       // Нет ошибки
        b.foo(3.14);     // Нет ошибки
        //b.foo("test"); // Ошибка, перекрывающая перегрузка с типом std::string есть только у наследника
    }

    {
        Derived d = Derived();
        //d.foo(42);   // Ошибка: нет подходящей функции в Derived
        //d.foo(3.14); // Ошибка: нет подходящей функции в Derived
        d.foo("test"); // Нет ошибки
    }

    {
        // При наследовании приоритет будет у базового класса, а не наследника
        Base b = Derived();
        b.foo(42);       // Нет ошибки, будет вызов Base::foo(int x)
        b.foo(3.14);     // Нет ошибки, будет вызов Base::foo(double x)
        b.foo("test");   // Нет ошибки, будет вызов Derived::foo(std::string x)
    }
}

} // namespace Example2_2
