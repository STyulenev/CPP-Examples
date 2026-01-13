#pragma once

#include <iostream>
#include <string>

/*
 * Template union
 *
 * Union можно сделать шаблонным - пример std::variant.
 *
 */
namespace Example6
{

template<typename T1, typename T2>
union Variant
{
    T1 value1;
    T2 value2;

    // Конструкторы
    Variant() : value1{} {} // инициализируем первый тип по умолчанию

    Variant(const T1& val) : value1(val) {}
    Variant(const T2& val) : value2(val) {}

    // Деструктор должен быть тривиальным
    ~Variant() {}

    // Методы для работы с данными
    void setFirst(const T1& val) {
        new (&value1) T1(val);
    }

    void setSecond(const T2& val) {
        new (&value2) T2(val);
    }
};

// Базовый случай
template<typename... Types>
union VariadicUnion;

// Рекурсивный случай
template<typename T, typename... Rest>
union VariadicUnion<T, Rest...> {
    T value;
    VariadicUnion<Rest...> rest;

    VariadicUnion() {}
    ~VariadicUnion() {}
};

// Конец рекурсии
template<>
union VariadicUnion<> {
    VariadicUnion() {}
    ~VariadicUnion() {}
};

// Вспомогательный класс для доступа по индексу
template<std::size_t I, typename Union>
struct UnionElement;

template<std::size_t I, typename T, typename... Rest>
struct UnionElement<I, VariadicUnion<T, Rest...>>
    : UnionElement<I-1, VariadicUnion<Rest...>> {};

template<typename T, typename... Rest>
struct UnionElement<0, VariadicUnion<T, Rest...>> {
    using type = T;
    using union_type = VariadicUnion<T, Rest...>;
};

void test()
{
    // Union с int и double
    Variant<int, double> v1(42);
    std::cout << "v1.value1 = " << v1.value1 << std::endl;

    v1.setSecond(3.14);
    std::cout << "v1.value2 = " << v1.value2 << std::endl;

    // Union со string и int
    Variant<std::string, int> v2;
    v2.setFirst("Hello");
    std::cout << "v2.value1 = " << v2.value1 << std::endl;

    VariadicUnion<int, double, char> u;

    u.value = 42; // Доступ к первому типу (int)
    std::cout << "int: " << u.value << std::endl;

    u.rest.value = 3.14; // Доступ ко второму типу (double)
    std::cout << "double: " << u.rest.value << std::endl;

    u.rest.rest.value = 'A'; // Доступ к третьему типу (char)
    std::cout << "char: " << u.rest.rest.value << std::endl;
}

} // namespace Example6
