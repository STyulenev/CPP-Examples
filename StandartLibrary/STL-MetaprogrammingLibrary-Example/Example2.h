#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Composite type categories
 * =======================================================================================================================================================================
 * Функции:
 * - is_fundamental
 * - is_arithmetic
 * - is_scalar
 * - is_object
 * - is_compound
 * - is_reference
 * - is_member_pointer
 */

namespace Example2 {

namespace CTP2 { // ------------------------------------ Проверка на арифметический тип (целочисленный или с плавающей точкой) (is_arithmetic)

struct SomeStruct {};

template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
void foo(T arg)
{}

void test()
{
    SomeStruct ss;

    //foo(ss);    // Ошибка
    foo(12);      // Ок
    foo(14.4);    // Ок
    foo('a');     // Ок
    //foo("sdf"); // Ошибка
}

} // CTP1



namespace CTP6 { // ------------------------------------ Проверка на ссылку (is_reference)

class Base {};

template<class T>
struct is_reference /*: std::false_type*/ { static const bool value = false; };

template<class T>
struct is_reference<T&> /*: std::true_type*/ { static const bool value = true; };

template<class T>
struct is_reference<T&&> /*: std::true_type*/ { static const bool value = true; };


template <typename T, std::enable_if_t<is_reference<T>::value, bool> = true >   // Используя is_reference
// template <typename T, std::enable_if_t<std::is_reference_v<T>, bool> = true> // Используя стандартный std::is_reference_v
void foo(T arg)
{
    std::cout << typeid(arg).name() << std::endl;
}

void test() {
    Base* b = new Base();
    Base b1;
    Base& b1_ref = b1;
    int a = 12;

    // Потребуется указать тип, иначе не определяется
    //foo<Base*>(b);     // Ошибка
    foo<Base&>(b1_ref);  // Ок
    //foo<int>(a);       // Ошибка
    foo<Base&&>(Base()); // Ок

    std::cout << std::boolalpha << is_reference<Base*>::value << std::endl;
    std::cout << std::boolalpha << is_reference<Base&>::value << std::endl;
    std::cout << std::boolalpha << is_reference<Base>::value << std::endl;
    std::cout << std::boolalpha << is_reference<Base&&>::value << std::endl;
    std::cout << std::boolalpha << is_reference<int>::value << std::endl;

    delete b;
}

} // CTP6

} // Example2
