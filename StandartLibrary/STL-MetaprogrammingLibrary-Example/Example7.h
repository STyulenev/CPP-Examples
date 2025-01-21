#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Type transformations
 * =======================================================================================================================================================================
 * Функции:
 * 1. Const-volatility specifiers
 * - remove_cv
 * - remove_const
 * - remove_volatile
 * - add_cv
 * - add_const
 * - add_volatile
 *
 * 2. References
 * - remove_reference
 * - add_lvalue_reference
 * - add_rvalue_reference
 *
 * 3. Sign modifiers
 * - make_signed
 * - make_unsigned
 *
 * 4. Arrays
 * - remove_extent
 * - remove_all_extents
 *
 * 5. Pointers
 * remove_pointer
 * add_pointer
 *
 * 6. Other transformations
 * - aligned_storage
 * - aligned_union
 * - decay
 * - remove_cvref
 * - enable_if
 * - conditional
 * - common_type
 * - common_reference
 * - basic_common_reference
 * - underlying_type
 * - result_of
 * - invoke_result
 * - void_t
 * - type_identity
 *
 */

namespace Example7 {

// ------------------------------------ Const-volatility specifiers ------------------------------------

namespace TT1_1 { // ------------------------------------ Пример удаления volatile и const (remove_cv)

template <typename T>
struct IsInt : std::is_same<T, int> {};

template <typename T>
struct DeleteCV : std::is_same<std::remove_cv<T>, int> {};

template <typename T>
constexpr bool IsInteger = std::conjunction<DeleteCV<T>, IsInt<T>>::value;

template <typename T, typename = typename std::enable_if<IsInteger<T>>>
void foo(T& arg)
{}

void test()
{
    volatile const int a = 12;
    const int b = 12;
    int c = 12;

    foo(a);     // Ок
    foo(b);     // Ок
    foo(c);     // Ок
    //foo(12);  // Ошибка
    //foo('c'); // Ошибка
}

} // namespace TT1_1



namespace TT1_2 { // ------------------------------------ Пример удаления const (remove_const)

template <typename T>
struct IsInt : std::is_same<T, int> {};

// Удаляется const для проверок в шапке шаблона
template <typename T>
struct DeleteConst : std::is_same<std::remove_const<T>, int> {};

template <typename T>
constexpr bool IsInteger = std::conjunction<DeleteConst<T>, IsInt<T>>::value;

template <typename T, typename = typename std::enable_if<IsInteger<T>>>
void foo(T& arg)
{
    // arg = 5; // Ошибка
    int& tmp = const_cast<int&>(arg);
    tmp = 6;
}

void test()
{
    const int a = 5;

    foo(a);     // Ок
    //foo(12);  // Ошибка
    //foo('c'); // Ошибка
}

} // namespace TT1_2



namespace TT1_3 { // ------------------------------------ Пример удаления volatile и const

template <typename T>
struct IsInt : std::is_same<T, int> {};

// Удаляется const для проверок в шапке шаблона
template <typename T>
struct DeleteVolatile : std::is_same<std::remove_const<T>, int> {};

template <typename T>
constexpr bool IsInteger = std::conjunction<DeleteVolatile<T>, IsInt<T>>::value;

template <typename T, typename = typename std::enable_if<IsInteger<T>>>
void foo(T& arg)
{}

void test()
{
    volatile int a = 5;

    foo(a);     // Ок
    //foo(12);  // Ошибка
    //foo('c'); // Ошибка
}


} // namespace TT1_3



namespace TT1_4 { // ------------------------------------ Пример удаления volatile (remove_volatile)

void test()
{

}

} // namespace TT1_4



// ------------------------------------ References ------------------------------------



namespace TT2_1 {

template <typename T, std::enable_if_t<std::is_same_v<std::remove_reference_t<T>, int>, bool> = true >
void foo(T& arg)
{}

void test()
{
    int a = 5;
    int& b = a;

    foo(a);     // Ок
    foo(b);     // Ок
    //foo(5U);  // Ошибка
    //foo(4.1); // Ошибка
}

} // namespace TT2_1

} // namespace Example7
