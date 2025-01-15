#pragma once

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


namespace CTP1 { // ------------------------------------ Проверка на фундаментальный тип (is_fundamental)

template <typename T, std::enable_if_t<std::is_fundamental<T>::value, bool> = true >
void foo(T arg)
{}

/*
 * Фундаментальные типы:
 * - arithmetic type (integral, float);
 * - void;
 * - nullptr_t.
 */
void test()
{
    std::nullptr_t n_ptr;
    int* i = new int(5);

    foo(n_ptr); // Ок std::nullptr_t
    //foo(i);   // Ошибка int*
    foo(*i);    // Ок int

    delete i;
}

} // CTP1



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

} // CTP2


namespace CTP3 { // ------------------------------------ Проверка на скалярный тип (is_scalar)

enum Enum {
    FIRST = 1,
    SECOND = 2
};

struct Base {};

template <typename T, std::enable_if_t<std::is_scalar<T>::value, bool> = true >
void foo(T arg)
{}

/*
 * Скалярные типы:
 * - arithmetic (integral, float);
 * - pointers;
 * - enum;
 * - pointer-to-member;
 * - nullptr_t.
 */
void test()
{
    std::nullptr_t n_ptr;
    int* i = new int(5);
    Base b;

    foo(n_ptr);       // Ок std::nullptr_t
    foo(i);           // Ок int*
    foo(*i);          // Ок int
    foo(Enum::FIRST); // Ок enum
    //foo(b);         // Ошибка Base

    delete i;
}

} // CTP3



namespace CTP4 { // ------------------------------------ Проверка на объект (is_object)

struct Base {};

template <typename T, std::enable_if_t<std::is_object<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    std::nullptr_t n_ptr;
    int* i = new int(5);
    Base b;
    int& i_r = *i;

    foo(n_ptr);       // Ок std::nullptr_t
    foo<int*>(i);     // Ок int*
    foo<int>(*i);     // Ок int
    foo(b);           // Ок Base
    //foo<int&>(i_r); // Ошибка int&

    delete i;
}

} // CTP4



namespace CTP5 { // ------------------------------------ Проверка на составной тип (is_compound)

struct Base {};

template <typename T, std::enable_if_t<std::is_compound<T>::value, bool> = true >
void foo(T arg)
{}

/*
 * Составные типы:
 * - array;
 * - function;
 * - object pointer;
 * - function pointer;
 * - member object pointer;
 * - member function pointer;
 * - reference, class;
 * - union;
 * - enumeration.
 */

void test()
{
    int* i = new int(5);
    Base b;
    int& i_r = *i;

    foo<int*>(i);   // Ок int*
    //foo<int>(*i); // Ошибка int
    foo(b);         // Ок Base
    foo<int&>(i_r); // Ок int&

    delete i;
}

} // CTP5



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
