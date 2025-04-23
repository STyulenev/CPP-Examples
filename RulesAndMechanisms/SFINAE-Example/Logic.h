#pragma once

#include <type_traits>

#include "SomeClass.h"

// Класс для проверки: класс не имеет метода print()
/*
 * Класс для проверки: класс не имеет метода print()
 */
template<typename Type, typename = void>
struct has_print : std::false_type
{};

/*
 * Класс для проверки: класс имеет метода print()
 */
template<typename Type>
struct has_print<Type, std::void_t<decltype(std::declval<Type>().print())>> : std::true_type
{};

/*
 * Шаблонная функция с проверкой в заголовке на метод print()
 */
template <typename T, typename = std::enable_if_t<has_print<T>::value, void>*>
void templatePrint(const T& value)
{
    value.print();
}

/*
 * Перегрузка для SomeClass2
 */
template <typename = std::true_type> // Можно убрать полностью
void templatePrint(const SomeClass2& value)
{
    value.print2();
}
