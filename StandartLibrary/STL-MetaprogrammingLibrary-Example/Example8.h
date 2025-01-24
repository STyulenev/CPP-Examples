#pragma once

#include <type_traits>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Logical operations
 * =======================================================================================================================================================================
 * Функции:
 * - conjunction
 * - disjunction
 * - negation
 *
 */

namespace Example8 {

namespace LO1 {  // ------------------------------------ Логическое И (conjunction)

template <typename T>
struct IsInteger : std::is_integral<T> {};
template <typename T>
struct IsPointer : std::is_pointer<T> {};

// Используем std::conjunction, чтобы проверить, является ли тип одновременно целым числом и указателем
template <typename T, typename U>
constexpr bool IsIntegerPointer = std::conjunction<IsInteger<T>, IsPointer<U>>::value;

template<typename T, std::enable_if_t<IsIntegerPointer<
                                          std::remove_pointer_t<T>, // long* != long и не std::is_integral, поэтому удаляем указатель
                                          T>, bool> = true >
//template<typename T, std::enable_if_t<std::conjunction<IsInteger<std::remove_pointer_t<T>>, IsPointer<T>>::value, bool> = true>
void foo(T a)
{}

template <typename T>
struct IsBool : std::is_same<T, bool> {};
template <typename T>
struct IsInt : std::is_same<T, int> {};

// Проверяем, что первый тип == bool, а второй == int
template <typename T, typename U>
constexpr bool IsBoolNInteger = std::conjunction<IsBool<T>, IsInt<U>>::value;

template<typename T, typename U, std::enable_if_t<IsBoolNInteger<T, U>, bool > = true>
void foo2(T a, U b)
{}

void test()
{
    long* a = new long(4);
    const char* b = "sdf";

    foo(a);                    // Ок
    //foo('s');                // Ошибка
    foo(b);                    // Ок
    //foo(12);                 // Ошибка
    //foo(std::string("sdf")); // Ошибка

    foo2(true, 22);   // Ок
    //foo2(22, true); // Ошибка
    //foo2(22, 22);   // Ошибка

    delete a;
}

} //namespace LO1



namespace LO2 {  // ------------------------------------ Логическое ИЛИ (disjunction)

template <typename T>
struct IsInteger : std::is_same<T, int> {};
template <typename T>
struct IsLong : std::is_same<T, long> {};

// Используем std::disjunction, чтобы проверить, является ли тип T - int или long
template <typename T>
constexpr bool IsIntegerOrLong = std::disjunction<IsInteger<T>, IsLong<T>>::value;

template<typename T, std::enable_if_t<IsIntegerOrLong<T>, bool> = true >
void foo(T arg)
{}

void test()
{
    foo(12);     // Ок
    foo(12L);    // Ок
    //foo(true); // Ошибка
    //foo(12UL); // Ошибка
    //foo('a');  // Ошибка
}

} // namespace LO2



namespace LO3 {  // ------------------------------------ Логическое НЕ (negation)

template <typename T>
struct NotInt : std::negation<std::is_same<T, int>> {};
template <typename T>
struct NotLong : std::negation<std::is_same<T, long>> {};

// Проверяем, что не long и не int
template <typename T>
constexpr bool IsNotIntegerOrLong = std::conjunction<NotInt<T>, NotLong<T>>::value;

template<typename T, std::enable_if_t<IsNotIntegerOrLong<T>, bool> = true >
void foo(T arg)
{}

void test()
{
    //foo(12);  // Ошибка
    //foo(12L); // Ошибка
    foo(true);  // Ок
    foo(12UL);  // Ок
    foo('a');   // Ок
}

} // namespace LO3

} // namespace Example8
