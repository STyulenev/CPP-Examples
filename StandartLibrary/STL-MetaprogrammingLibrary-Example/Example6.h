#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Type relationships
 * =======================================================================================================================================================================
 * Функции:
 * - is_same
 * - is_base_of
 * - is_virtual_base_of (C++26)
 * - is_convertible
 * - is_nothrow_convertible
 * - is_layout_compatible
 * - is_pointer_interconvertible_base_of
 * - is_invocable
 * - is_invocable_r
 * - is_nothrow_invocable
 * - is_nothrow_invocable_r
 *
 */

namespace Example6 {

namespace TR1 { // ------------------------------------ Проверка на конкретный тип (is_same)

template <typename T, std::enable_if_t<std::is_same_v<T, bool>, bool> = true >
void foo(T arg)
{}

void test()
{
    foo(true);    // Ок
    //foo(12);    // Ошибка
    //foo("sdf"); // Ошибка
}

} // namespace TR1



namespace TR2 { // ------------------------------------ Проверка на наследника базового класса (is_base_of)

struct Base
{};

struct Derived : public Base
{};

template <typename T, typename U, std::enable_if_t<std::is_base_of_v<T, U>, bool> = true >
void foo(T base, U derived)
{}

template <typename T, typename U, std::enable_if_t<std::is_base_of_v<T, U>, bool> = true >
void foo(T base)
{}

void test()
{
    Base b;
    Derived d;

    foo(b, d);     // Ок
    //foo(12, 13); // Ошибка
    //foo(d, b);   // Ошибка

    foo<Base, Derived>(d);   // Ок
    //foo<Derived, Base>(d); // Ошибка
}

} // namespace TR2



namespace TR4 { // ------------------------------------ Проверка на конвертацию (is_convertible)

template <typename T, std::enable_if_t<std::is_convertible_v<T, int>, bool> = true >
void foo(T arg)
{}

void test()
{
    foo(true);  // Ок bool
    foo(12U);   // Ок unsigned int
    foo(12.3);  // Ок double
    foo(12.3);  // Ок float
    foo(12.3L); // Ок long double
    foo('A');   // Ок char
    //foo("A"); // Ошибка const char[2]
}

} // namespace TR4



namespace TR8 { // ------------------------------------ Проверка на вызываемый объект - лямбда, функция и т.д. (is_invocable)

template <typename T, std::enable_if_t<std::is_invocable<T>::value, bool> = true >
void foo(T* f)
{
    std::cout << "result = " << std::invoke(f) << std::endl;
}

int function() {
    return 0;
}

void test()
{
    int (*f)() = function;

    foo(f);      // Ок bool
    //foo(12U);  // Ошибка unsigned int
    //foo(12.3); // Ошибка double
}

} // namespace TR8

} // namespace Example6
