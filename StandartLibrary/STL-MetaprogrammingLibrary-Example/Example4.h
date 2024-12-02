#pragma once

#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Supported operations
 * =======================================================================================================================================================================
 * Функции:
 * - is_constructible / is_trivially_constructible / is_nothrow_constructible
 * - is_default_constructible / is_trivially_default_constructible / is_nothrow_default_constructible
 * - is_copy_constructible / is_trivially_copy_constructible / is_nothrow_copy_constructible
 * - is_move_constructible / is_trivially_move_constructible / is_nothrow_move_constructible
 * - is_assignable / is_trivially_assignable / is_nothrow_assignable
 * - is_copy_assignable / is_trivially_copy_assignable / is_nothrow_copy_assignable
 * - is_move_assignable / is_trivially_move_assignable / is_nothrow_move_assignable
 * - is_destructible / is_trivially_destructible / is_nothrow_destructible
 * - has_virtual_destructor
 * - is_swappable_with/is_swappableis_nothrow_swappable_with/is_nothrow_swappable
 * - reference_constructs_from_temporary (C++23)
 * - reference_converts_from_temporary (C++23)
 */


namespace Example4 {

namespace SO1 { // ------------------------------------ Проверка на (is_constructible / is_trivially_constructible / is_nothrow_constructible)

struct Base1 {
    Base1() {}
    Base1(int n) {}
    Base1(double n) {}
    // ...

};

struct Base2 {
    Base2() {}
    Base2(std::string n) noexcept {}
    // ...

};

// Проверяет есть ли конструктор с аргументом int
template <typename T, std::enable_if_t<std::is_constructible_v<T, int>, bool> = true >
void foo1(T arg)
{}

// Проверяет есть ли конструктор с аргументом std::string с nothrow
template <typename T, std::enable_if_t<std::is_nothrow_constructible_v<T, std::string>, bool> = true >
void foo2(T arg)
{}

void test()
{
    Base1 b1;
    Base2 b2;

    foo1(b1);   // Ок
    //foo1(b2); // Ошибка

    //foo2(b1); // Ошибка
    foo2(b2);   // Ок
}

} // namespace SO1

} // namespace Example4
