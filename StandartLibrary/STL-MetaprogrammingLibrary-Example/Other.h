#pragma once

#include <functional>
#include <type_traits>
#include <iostream>

#include <vector>
#include <list>

#include <map>
#include <set>

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

// Запись до C++11
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

// Запись с C++11
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



namespace E6 { // ------------------------------------ Проверка на std контейнер (std, boost, qt ...)

template<typename T, typename = void>
struct is_container : std::false_type
{};

template<typename T>
struct is_container<T, std::void_t<
        typename T::value_type,
        typename T::size_type,
        typename T::allocator_type,
        typename T::iterator,
        typename T::const_iterator,
        decltype(std::declval<T>().size()),
decltype(std::declval<T>().begin()),
decltype(std::declval<T>().end()),
decltype(std::declval<T>().cbegin()),
decltype(std::declval<T>().cend())>> : std::true_type
{};

template <typename T, std::enable_if_t<is_container<T>::value, bool> = true>
void foo(T arg)
{}

void test()
{
    std::vector<int> v = {1, 2, 3};
    std::list<int> l = {1, 2, 3};
    std::map<int, int> m = { {1, 2}, {2, 3} };
    std::set<int> s = {1, 2, 3};

    //foo(12);             // Ошибка
    //foo(12L);            // Ошибка
    foo(v);                // Ок
    foo(l);                // Ок
    foo(std::string("s")); // Ок
    foo(m);                // Ок
    foo(s);                // Ок
}

} // E6



namespace E7 { // ------------------------------------ Проверка на карту (std, boost, qt ...)

template<class T>
struct is_map : std::is_same<typename T::value_type, std::pair<const typename T::key_type, typename T::mapped_type>> {};

template <typename T, typename = typename std::enable_if_t<is_map<T>::value, bool> >
void foo(T arg)
{}

void test()
{
    std::vector<int> v = {1, 2, 3};
    std::list<int> l = {1, 2, 3};
    std::map<int, int> m = { {1, 2}, {2, 3} };
    std::set<int> s = {1, 2, 3};

    //foo(12);               // Ошибка
    //foo(12L);              // Ошибка
    //foo(v);                // Ошибка
    //foo(l);                // Ошибка
    //foo(std::string("s")); // Ошибка
    foo(m);                  // Ок
    //foo(s);                // Ошибка
}

} // E7



namespace E8 { // ------------------------------------ Проверка в возвращаемом типе (на примере арифметического типа)

template <class T>
typename std::enable_if_t<std::is_arithmetic_v<T>, T>
foo(T t)
{
    std::cout << "foo<arithmetic T>\n";
    return t;
}

enum E {
    FIRST = 0
};

void test()
{
    foo(12);                 // Ок
    foo(12L);                // Ок
    foo('c');                // Ок
    //foo(E::FIRST);         // Ошибка
    //foo(std::string("s")); // Ошибка
}

} // E8



namespace E9 { // ------------------------------------ Пример концепта, но с другой записью

#if __cplusplus >= 202002L // 202003L

template <class T>
concept UnignedIntegral = std::is_integral_v<T> && std::is_unsigned_v<T>;

template <UnignedIntegral T>
void foo(T val)
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
    unsigned int i = 12;
    unsigned long l = 12;

    //foo(-12);  // Ошибка
    //foo(12L);  // Ошибка
    //foo('c');  // Ошибка
    foo(i);      // Ок
    foo(l);      // Ок
}

} // E9

} // namespace Other
