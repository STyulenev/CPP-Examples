#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                                           Other
 * =======================================================================================================================================================================
 *
 */

namespace Other {

namespace E1 { // ------------------------------------ Проверка на существование класса с метода print (без проверки на тип и с проверкой на тип) (Вариант 1)

// Тестовый класс
class Base1 {
public:
    void print() {
        // ...
    }
};

// Тестовый класс
class Base2 {
public:
    int print() {
        return 0;
    }
};

template<class T>
struct CheckMethod {
    typedef void(T::*P)(void);
    //typedef int(T::*P)(void); // Для foo2, чтобы работало с Base2 (проверка типа)

    // Проверка на метод print
    template<class U, P = &U::print>
    struct True { char dummy[2]; };

    typedef char False;

    static False detect(...); // Элипсис для всех остальных случаев (указан без тела, т.к. вызова не будет)

    template<class U>
    static True<U> detect(U*); // Метод detect для проверки на нужный метод

    // При вызове detect(static_cast<T*>(0) компилятор пробует подобрать подходящую перегрузку. Сначала шаблонную, потом
    // элипсис (приоритет ниже). Просле нахождении нужного метода будет проведена проверка типа и записан результат.
    static const bool exists = (sizeof(False) != sizeof(detect(static_cast<T*>(0))));
};

// Методы Print для проверки + вызова метода
template<class T, bool b = CheckMethod<T>::exists>
struct Print;

template<class T>
struct Print<T, true> {
    static void print(const T &t){
        // ...
    }
};

template<class T>
struct Print<T, false> {
    static void print(const T &t){
        // ...
    }
};

// Не проверяет тип
template<class T>
void foo1(const T &t){
    Print<T>::print(t);
}

// Будет проверка на полное соответствие - тип возвращаемого значения, тип аргументов, константность.
template<class T, std::enable_if_t<CheckMethod<T>::exists, bool> = true>
void foo2(const T& t)
{}

void test()
{
    Base1 b1;
    Base2 b2;

    foo1(b1);   // Ок
    foo1(b2);   // Ок
    //foo1(12); // Ошибка

    foo2(b1);   // Ок
    //foo2(b2); // Ошибка
    //foo2(12); // Ошибка
}

} // E2



namespace E2 { // ------------------------------------ Проверка на существование класса с метода print (Вариант 2)

class Base1 {
    void print() {} // private
};

struct Base2 {
    void print() {} // public
};

template <typename T, typename ENABLE = void>
struct CheckMethod : std::false_type { /*static const bool value = false;*/ };

template <typename T>
struct CheckMethod<T, decltype(std::declval<T>().print())> : std::true_type { /*static const bool value = true;*/ };

// std::declval преобразует любой тип в ссылочный тип

template <typename T, std::enable_if_t<CheckMethod<T>::value, bool> = true /* или typename = CheckMethod<T>*/ >
void foo(T arg)
{}

void test()
{
    Base1 b1;
    Base2 b2;

    //foo(b1); // Ошибка
    foo(b2);   // Ок

    std::cout << std::boolalpha << CheckMethod<Base1>::value << std::endl; // false
    std::cout << std::boolalpha << CheckMethod<Base2>::value << std::endl; // true
}

} // E2



namespace E3 { // ------------------------------------ Проверка класса через typedef

struct Base0 {
    typedef long double money;
};

struct Base1 {
    typedef int integer;
};

struct Base2 {
    typedef int integer;
    typedef short int small_integer;
};

// is_Base2 нужен для большого количества проверок
template<typename T, typename = void>
struct is_Base2 : std::false_type {};

template<typename T>
struct is_Base2<T, std::void_t<typename T::integer, typename T::small_integer>> : std::true_type {};

template <typename T, typename = typename T::integer>
// template <typename T, typename = typename T::integer, typename = typename T::small_integer> // Будет error, foo1 is ambiguous
void foo1(T arg)
{}

// Будет error, foo1 is ambiguous => создаём foo2
/*template <typename T, typename = typename T::integer, typename = typename T::small_integer>
void foo1(T arg)
{}*/

template <typename T, std::enable_if_t<is_Base2<T>::value, bool> = true >
void foo2(T arg)
{}

void test()
{
    Base0 b0;
    Base1 b1;
    Base2 b2;

    //foo1(b0); // Ошибка
    foo1(b1);   // Ок
    foo1(b2);   // Ок

    //foo2(b0); // Ошибка
    //foo2(b1); // Ошибка
    foo2(b2);   // Ок
}

} // E3



namespace E4 { // ------------------------------------ Ветвление для возврщаемого типа

namespace Impl
{
template <typename NotInt> inline constexpr bool isInt = false;
template <> inline constexpr bool isInt<int>           = true;
template <> inline constexpr bool isInt<char>          = true;
template <> inline constexpr bool isInt<unsigned int>  = true;
template <> inline constexpr bool isInt<long>          = true;
template <> inline constexpr bool isInt<long long>     = true;
// ...
}

// Если входит в Impl, то вернёт int
template <typename T>
auto foo(T arg) -> std::enable_if_t<Impl::isInt<T>, int>
{
    return 12;
}

// Если входит в Impl, то вернёт std::string
template <typename T>
auto foo(T arg) -> std::enable_if_t<!Impl::isInt<T>, std::string>
{
    return std::string("number");
}

void test()
{
    std::cout << foo(12) << std::endl;                   // return int
    std::cout << foo('a') << std::endl;                  // return int
    std::cout << foo(54.11) << std::endl;                // return std::string
    std::cout << foo(std::string("sfsdf")) << std::endl; // return std::string
}

} // E4



namespace E5 { // ------------------------------------ Проверка через concept

#if __cplusplus >= 202002L // 202003L

template <typename T>
concept IsInt = std::is_same_v<T, int> || std::is_same_v<T, long>; // ... is_convertible_v ...

template <class T> requires IsInt <T>
void foo(T s)
{}

#else

template <typename T>
void foo(T)
{
    std::cout << "Unknown standart" << std::endl;
}

#endif

void test()
{
    foo(12);                 // Ок
    foo(12L);                // Ок
    //foo(12.01);            // Ошибка
    //foo(std::string("s")); // Ошибка
}

} // E5



} // namespace Other
