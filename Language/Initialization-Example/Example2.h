#pragma once

#include <iostream>

/*
 * Пример последовательноcти инициализации полей класса и наследников
 *
 * - В классе сначала инициализируются поля, затем отрабатывает конструктор.
 * - При наследовании сначала инициализируются родительские классы.
 * - Поля инициализируются сверху вниз, по очереди, при удалении в обратном направлении.
 * - Наследники инициализируются слева направо, при удалении в обратном направлении.
 * - При разрушении объекта сначала отрабатывает деструктор, а затем удаляются поля.
 */

namespace Example2 {

struct Field1
{
    Field1() { std::cout << "Field1()" << std::endl; }
    ~Field1() { std::cout << "~Field1()" << std::endl; }
};

struct Field2
{
    Field2() { std::cout << "Field2()" << std::endl; }
    ~Field2() { std::cout << "~Field2()" << std::endl; }
};

struct Field3
{
    Field3() { std::cout << "Field3()" << std::endl; }
    ~Field3() { std::cout << "~Field3()" << std::endl; }
};

struct Base1
{
    Field1 bf1;

    Base1() { std::cout << "Base1()" << std::endl; }
    ~Base1() { std::cout << "~Base1()" << std::endl; }
};

struct Base2
{
    Field1 bf1;

    Base2() { std::cout << "Base2()" << std::endl; }
    ~Base2() { std::cout << "~Base2()" << std::endl; }
};

struct Derived1 : public Base1
{
    Field1 d1f1;
    Field2 d1f2;
    Field3 d1f3;

    Derived1() { std::cout << "Derived1()" << std::endl; }
    ~Derived1() { std::cout << "~Derived1()" << std::endl; }
};

struct Derived2 : public Derived1
{
    Derived2() { std::cout << "Derived2()" << std::endl; }
    ~Derived2() { std::cout << "~Derived2()" << std::endl; }
};

struct Derived3 : public Base1, public Base2
{
    Derived3() { std::cout << "Derived3()" << std::endl; }
    ~Derived3() { std::cout << "~Derived3()" << std::endl; }
};

void test1()
{
    std::cout << std::endl;

    Derived2 d2 = Derived2();

    std::cout << std::endl;
}

void test2()
{
    std::cout << std::endl;

    Derived3 d3 = Derived3();

    std::cout << std::endl;
}

} // namespace Example2
