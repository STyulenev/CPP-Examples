#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Type properties
 * =======================================================================================================================================================================
 * Функции:
 * - is_const
 * - is_volatile
 * - is_trivial
 * - is_trivially_copyable
 * - is_standard_layout
 * - is_pod (deprecated in C++20)
 * - is_literal_type (removed in C++20)
 * - has_unique_object_representations
 * - is_empty
 * - is_polymorphic
 * - is_abstract
 * - is_final
 * - is_aggregate
 * - is_implicit_lifetime
 * - is_signed
 * - is_unsigned
 * - is_bounded_array
 * - is_unbounded_array
 * - is_scoped_enum (C++23)
 *
 */

namespace Example3 {

namespace TP1 { // ------------------------------------ Проверка на const (is_const)

template<class T> struct is_const          : std::false_type {};
template<class T> struct is_const<const T> : std::true_type {};

// template <typename T, std::enable_if_t<is_const<T>::value, bool> = true>
template <typename T, std::enable_if_t<std::is_const<T>::value, bool> = true>
void foo(T& arg) // Без ссылки не пройдут именованные константы.
{}

void test()
{
    const int a = 12;

    foo(a);             // Ок для T& arg
    foo<const int>(a);  // Ок для T arg
    foo<const int>(12); // Ок
    //foo(12);          // Ошибка
}


} // TP1



namespace TP2 { // ------------------------------------ Проверка на volatile (is_volatile)

template <typename T, std::enable_if_t<std::is_volatile<T>::value, bool> = true>
void foo(T& arg)
{}

void test()
{
    volatile int a = 12;

    foo(a);               // Ок для T& arg
    //foo<const int>(12); // Ошибка
    //foo(12);            // Ошибка
}

} // TP2



namespace TP3 { // ------------------------------------ Проверка на тривиальность (is_trivial и is_trivially_copyable)

struct TrivialClass
{
    TrivialClass() = default;
    TrivialClass(const TrivialClass&) = default;
    TrivialClass(TrivialClass&&) = default;
    TrivialClass& operator=(const TrivialClass&) = default;
    TrivialClass& operator=(TrivialClass&&) = default;
    ~TrivialClass() = default;
};

struct NonTrivialClass
{
    NonTrivialClass() {} // Для нетривиальности достаточно сделать свою реализацию конструктора != is_trivial
    NonTrivialClass(const NonTrivialClass& c) {} // != is_trivially_copyable_v
};

template <typename T, std::enable_if_t<std::is_trivial<T>::value, bool> = true>
void foo(T& arg)
{}

void test()
{
    TrivialClass tc;
    NonTrivialClass ntc;

    foo(tc);    // Ок
    //foo(ntc); // Ошибка
}

} // TP3

namespace TP5 { // ------------------------------------ Проверка на стандартную компоновку (is_standard_layout)
/*
 * Следующие типы называются типами стандартной компоновки:
 * - скалярные типы;
 * - типы классов стандартной компоновки;
 * - массивы таких типов;
 * - версии этих типов, соответствующие cv.
*/
struct StandartLayout {
    int a;
    // ...
};

struct NonStandartLayout : public StandartLayout {
    int a;
};

template <typename T, std::enable_if_t<std::is_standard_layout<T>::value, bool> = true>
void foo(T& arg)
{}

void test()
{
    StandartLayout sl;
    NonStandartLayout nsl;

    foo(sl);    // Ок
    //foo(nsl); // Ошибка
}

} // TP5



namespace TP9 { // ------------------------------------ Проверка на пустой класс/структуру (is_empty)

struct Base1 {};

struct Base2 {
    static int count;
};

int Base2::count = 0;

struct Base3 {
    int count = 0;
};

template <typename T, std::enable_if_t<std::is_empty<T>::value, bool> = true>
void foo(T& arg)
{}

void test()
{
    Base1 b1;
    Base2 b2;
    Base3 b3;

    foo(b1);   // Ок
    foo(b2);   // Ок
    //foo(b3); // Ошибка
}

} // TP9



namespace TP10 { // ------------------------------------ Проверка на пустой класс/структуру (is_empty)

// Полиморфный класс/структура - это класс/структура, не являющийся объединением, который объявляет или наследует по крайней мере одну виртуальную функцию.

struct Base1
{};

struct Base2 {
    virtual void print() {};
};

struct Base3 : public Base2 {
    void print() override {

    }
};

template <typename T, std::enable_if_t<std::is_polymorphic<T>::value, bool> = true>
void foo(T arg)
{}

void test()
{
    Base1 b1;
    Base2 b2;
    Base3 b3;

    //foo(b1); // Ошибка
    foo(b2);   // Ок
    foo(b3);   // Ок
}

} // TP9

} // namespace Example3



































