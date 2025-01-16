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

namespace TT1_1 { // ------------------------------------ Пример удаления volatile и const

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

namespace TT1_4 { // ------------------------------------ Пример удаления volatile и const


void test()
{

}

} // namespace TT1_1

} // namespace Example7
