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
 * - is_pod
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

namespace TP1 { // ------------------------------------ Проверка на const (is_const )

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



} // namespace Example3
