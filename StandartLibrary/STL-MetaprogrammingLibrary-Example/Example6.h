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



namespace TR5 { // ------------------------------------ Проверка на конвертацию (is_nothrow_convertible)

struct Base {
    operator int() {
        return 0;
    }

    operator double() noexcept {
        return 0.0;
    }
};

template <typename T, typename V, std::enable_if_t<std::is_nothrow_convertible_v<T, V>, bool> = true >
void foo(T arg)
{}

void test()
{
    Base b;

    foo<Base, double>(b);  // Ок
    //foo<Base, int>(b);   // Ошибка
    //foo<Base, short>(b); // Ошибка
}

} // namespace TR5



namespace TR6 { // ------------------------------------ Проверка на конвертацию (is_layout_compatible)

struct Base2;

struct Base1 {
    int    a;
    double b;
};

struct Base2 {
    long  a;
    float b;
};

#if __cplusplus >= 202302L // 202003L

template <typename T, typename V, std::enable_if_t<std::is_is_layout_compatible_v<T, V>, bool> = true >
void foo(T arg1, V arg2)
{}

void test()
{
    Base1 b1;
    Base2 b2;

    foo(b1, b2);  // Ок
    //foo<Base, int>(b);   // Ошибка
    //foo<Base, short>(b); // Ошибка
}

#else

void test()
{
    std::cout << "Unknown standart" << std::endl;
}

#endif

} // namespace TR6



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
