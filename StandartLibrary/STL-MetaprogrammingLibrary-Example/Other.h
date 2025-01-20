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

namespace E1 { // ------------------------------------ Проверка на существование класса с методом print (без проверки на тип и с проверкой на тип) (Вариант 1)

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

// Если не входит в Impl, то вернёт std::string
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



namespace E10 { // ------------------------------------ Пример типизированного шаблона с частными случаями

template <int N>
struct Base {
    static const int value = N * N;
};

template <>
struct Base<0> {
    static const int value = 0;
};

template <>
struct Base<1> {
    static const int value = 1;
};

void test()
{
    std::cout << "value = " << Base<10>::value << std::endl;
    std::cout << "value = " << Base<0>::value << std::endl;
    std::cout << "value = " << Base<1>::value << std::endl;
}

} // E10


namespace E11 { // ------------------------------------ Пример проверки значения во время компиляции

struct Value {};
struct Color {};
struct Size {};
struct Point {};

enum class Property {
    Color,
    StrokeColor,
    Opacity,
    Size,
    Position,
};

class Dom {
public:
    template<Property prop, typename AnyValue>
    void setValue(const std::string& obj, AnyValue value) {
        setValue(std::integral_constant<Property, prop>{}, obj, value);
    }

private:
    // Специализированные скрытые методы
    void setValue(std::integral_constant<Property, Property::Color> type, const std::string &obj, Color col) {
        std::cout << " update color property" << std::endl;
    }

    void setValue(std::integral_constant<Property, Property::StrokeColor> type, const std::string &obj, Color col) {
        std::cout << " update stroke color property" << std::endl;
    }

    void setValue(std::integral_constant<Property, Property::Size> type, const std::string &obj, Size size) {
        std::cout << " update size property" << std::endl;
    }

};

void test()
{
    Dom domObj;

    domObj.setValue<Property::Color>("layer1.rect1", Color());  // Ок
    //domObj.setValue<Property::Color>("layer1.rect1", Size()); // Ошибка
    domObj.setValue<Property::Size>("layer1.rect1", Size());    // Ок
}

} // E11



namespace E12 { // ------------------------------------ Пример проверки веса переменной

template <class T, class = void>
struct is_two_or_eight_bytes : std::false_type {};

template <class T>
struct is_two_or_eight_bytes<T, std::enable_if_t<
        std::alignment_of<T>::value == 2 || std::alignment_of<T>::value == 8
        >> : std::true_type {};

template <typename T, std::enable_if_t<is_two_or_eight_bytes<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    short int a = 5;

    //foo(5);  // Ошибка, int = 4
    foo(12.1); // Ok, double = 8
    foo(5UL);  // Ok, unsigned long = 8
    foo(5UL);  // Ok, unsigned long = 8
    foo(a);    // Ok, short int = 2
}

} // E12



namespace E13 { // ------------------------------------ Проверка на существование класса с метода (Вариант 3)

// Проверка наличия метода size
template <typename T>
class has_size_method {
private:
    template <typename U>
    static auto check(int) -> decltype(std::declval<U>().size(), std::true_type{});

    template <typename>
    static std::false_type check(...);

public:
    static const bool value = decltype(check<T>(0))::value;
};

// Функция для типов с методом size
template <typename T>
typename std::enable_if<has_size_method<T>::value, void>::type
foo(const T& obj) {
    std::cout << "Size: " << obj.size() << std::endl;
}

// Функция для типов без метода size
template <typename T>
typename std::enable_if<!has_size_method<T>::value, void>::type
foo(const T& obj) {
    std::cout << "No size method available" << std::endl;
}

void test()
{
    std::vector<int> vec = { 1, 2, 3, 4 };
    int arr[] = { 1, 2, 3, 4 };

    foo(vec);
    foo(arr);
    foo(12.1);
    foo(5UL);
    foo(5UL);
}

} // E13



namespace E14 { // ------------------------------------ Проверка на валидацию в шапке шаблона через методы класса/структуры

constexpr bool is_valid(char c) {
    constexpr std::string_view valid ="8123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    return valid.find(c) != std::string_view::npos;
}

template<size_t N>
struct Format {
    constexpr Format(const char (&str)[N]) {
        std::copy_n(str, N, value);
    }

    constexpr bool isValid() const {
        if constexpr (N == 0) {
            return false;
        }

        for (char ch : value) {
            if (ch != '\0' && !is_valid(ch)) {
                return false;
            }
        }

        return true;
    }

    constexpr std::string_view format() const {
        return value;
    }

    char value[N];
};

template<Format fmt, std::enable_if_t<fmt.isValid(), bool> = true>
void foo() {
    std::cout /*<< std::boolalpha << "Status: " << fmt.isValid()*/ << " Processing string: " << fmt.format() << std::endl;
}

void test()
{
   foo<"Valid123">();       //  Ок
   //foo<"Invalid@Char">(); // Ошибка
}

} // E14

} // namespace Other
