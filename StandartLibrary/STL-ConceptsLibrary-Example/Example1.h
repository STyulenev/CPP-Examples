#pragma once

#include <concepts>
#include <iostream>

#include <memory>

/*
 * =======================================================================================================================================================================
 *                                                                 Core language concepts
 * =======================================================================================================================================================================
 *
 * Функции:
 * - same_as
 * - derived_from
 * - convertible_to
 * - common_reference_with
 * - common_with
 * - integral
 * - signed_integral
 * - unsigned_integral
 * - floating_point
 * - assignable_from
 * - swappable
 * - swappable_with
 * - destructible
 * - constructible_from
 * - default_initializable
 * - move_constructible
 * - copy_constructible
 *
 */

namespace Example1 {

namespace CL1 { // ------------------------------------ Пример same_as

template <class T>
concept IsInt = std::same_as<T, int>; // || std::convertible_to<T, int>

template <class T> requires IsInt<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    //foo(i);                 // Ошибка
    //foo(12L);               // Ошибка
    //foo('c');               // Ошибка
    //foo(2.1);               // Ошибка
    //foo(std::string("12")); // Ошибка
}

} // namespace CL1



namespace CL2 { // ------------------------------------ Пример derived_from

class Base {};

class D1 : public Base {};

class D2 : private Base {};

template <class T>
concept IsDerivedFromBase = std::derived_from<T, Base>;

template <class T> requires IsDerivedFromBase<T>
void foo(T arg)
{}

void test()
{
    Base b;
    D1 d1;
    D2 d2;

    foo(b);     // Ок
    foo(d1);    // Ок
    //foo(d2);  // Ошибка
    //foo(12L); // Ошибка
}

} // namespace CL2



namespace CL3 { // ------------------------------------ Пример convertible_to

template <class T>
concept IsToInt = std::same_as<T, int> || std::convertible_to<T, int>;

template <class T> requires IsToInt<T>
void foo(T arg)
{}

void test()
{
    unsigned int i = 12;

    foo(12);                  // Ок
    foo(i);                   // Ок
    foo(12L);                 // Ок
    foo('c');                 // Ок
    foo(2.1);                 // Ок
    //foo(std::string("12")); // Ошибка
}

} // namespace CL3



namespace CL4 { // ------------------------------------ Пример common_reference_with

class Base {};

class D1 : public Base {};

class D2 : private Base {};

template <class T>
concept IsRefBase = std::common_reference_with<T, Base>;

template <class T> requires IsRefBase<T>
void foo(T arg)
{}

void test()
{
    Base b;
    D1 d1;
    D2 d2;

    foo(std::move(b));    // Ок
    foo(std::move(d1));   // Ок
    //foo(std::move(d2)); // Ошибка
    //foo(12L);           // Ошибка
}

} // namespace CL4



namespace CL13 { // ------------------------------------ Пример common_reference_with

class Base1 {};

class Base2
{
public:
    Base2() {}

    static Base2& getBase2() {
        static Base2 b2;

        return b2;
    }

private:
    ~Base2() {}
};


template <class T>
concept IsDestructible = std::destructible<T>;

template <class T> requires IsDestructible<T>
void foo(T arg)
{}

void test()
{
    Base1 b1;

    foo(b1);                  // Ок
    //foo(Base2::getBase2()); // Ошибка
}

} // namespace CL13

} // namespace Example1
