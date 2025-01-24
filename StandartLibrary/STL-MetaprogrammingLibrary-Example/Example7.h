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



namespace TT1_3 { // ------------------------------------ Пример удаления volatile (remove_volatile)

template <typename T>
struct IsInt : std::is_same<T, int> {};

// Удаляется const для проверок в шапке шаблона
template <typename T>
struct DeleteVolatile : std::is_same<std::remove_volatile<T>, int> {};

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



namespace TT1_4 { // ------------------------------------ Пример добавления volatile и const (add_cv)

struct Base
{
    void m() { std::cout << " - Non-cv" << std::endl; }
    void m() const { std::cout << " - Const" << std::endl; }
    void m() volatile { std::cout << " - Volatile" << std::endl; }
    void m() const volatile { std::cout << " - Const-volatile" << std::endl; }
};

template <typename T>
void foo()
{
    T t;
    t.m();
}

void test()
{
    Base b;

    foo<std::add_cv<Base>::type>();
}

} // namespace TT1_4



namespace TT2_1 { // ------------------------------------ Пример удаления ссылки (remove_reference)

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



namespace TT3_1 { // ------------------------------------ Пример приведение к знаковой переменной (make_signed)

template <typename T, std::enable_if_t<std::is_same_v<std::make_signed_t<T>, int>, bool> = true >
void foo(T arg)
{}

void test()
{
    foo(5U);    // Ок
    foo(5);     // Ок
    //foo(5.5); // Ошибка
}

} // namespace TT3_1



namespace TT3_2 { // ------------------------------------ Пример приведение к беззнаковой переменной (make_signed)

template <typename T, std::enable_if_t<std::is_same_v<std::make_unsigned_t<T>, unsigned int>, bool> = true >
void foo(T arg)
{}

void test()
{
    foo(5U);    // Ок
    foo(5);     // Ок
    //foo(5.5); // Ошибка
}

} // namespace TT3_2



namespace TT6_1 { // ------------------------------------ Пример создания хранилища (aligned_storage)

template<class T, std::size_t N>
void foo()
{
    std::aligned_storage_t<sizeof(T), alignof(T)> data[N];
    std::size_t m_size = N;

     // Конструктор
    ::new(&data[1]) T(1);

     // Чтение
    std::cout << "data[1] = " << *std::launder(reinterpret_cast<const T*>(&data[1])) << std::endl;

    // Очистка
    for (std::size_t pos = 0; pos < m_size; ++pos)
        std::destroy_at(std::launder(reinterpret_cast<T*>(&data[pos])));
}

void test()
{
    foo<int, 5>();
}

} // namespace TT6_1



namespace TT6_3 { // ------------------------------------ Пример неявные преобразований (decay)

// decay - применяет неявные преобразования lvalue-to-rvalue, array-to-pointer и function-to-pointer к типу T

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, int>, bool> = true >
void foo(T arg)
{}

void test()
{
    int a = 5;

    foo<int&>(a);  // Ок
    foo<int>(5);   // Ок
    //foo(5.1);    // Ошибка
    foo<int&&>(5); // Ок
}

} // namespace TT6_3



namespace TT6_5 { // ------------------------------------ Пример шаблонного if (enable_if)

// Тест-функция для получения true/false значения
constexpr bool status(const bool s) {
    return s;
}

template<bool s, class T, std::enable_if_t<status(s), bool> = true>
void foo(T arg)
{}

void test()
{
    //foo<false>(5); // Ок
    foo<true>(5);    // Ошибка
}

} // namespace TT6_5



namespace TT6_6 { // ------------------------------------ Пример условия (conditional)

// Если B == true, то тип возвращаемого значения T, иначе U

template<bool B, typename T, typename U >
std::conditional<B, T, U>::type foo(T arg1, U arg2)
{
    return B ? arg1 : arg2;
}

void test()
{
    std::cout << "type value: " << foo<true>(1, 1.1) << std::endl;
    std::cout << "type value: " << foo<false>(1, 1.1) << std::endl;
}

} // namespace TT6_6

} // namespace Example7
