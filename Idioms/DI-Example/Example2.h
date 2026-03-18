#pragma once

#include <experimental/type_traits>

namespace Example2
{

// До C++ 11
namespace V1 {

template <bool B, class T = void>
struct enable_if { };

template <class T>
struct enable_if<true, T> { typedef T type; };

template <typename T>
struct has_plus
{
    // Этот тип необходим для различения перегрузок по размеру.
    typedef char yes[1];
    typedef char no[2];

    // SFINAE: проверка на корректность (T + T)
    template <typename U>
    static yes& test(char (*)[
        sizeof( (*(U*)0) + (*(U*)0))
    ]);

    // Для провала
    template <typename U>
    static no& test(...);

public:
    enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};

template <class T>
typename enable_if<has_plus<T>::value, T>::type
sum(const T& v1, const T& v2)
{
    return v1 + v2;
}

} // namespace V1




// C++ 11 (используя SFINAE)
namespace V2 {

template <class T, class = void>
struct has_plus : std::false_type { };

template <class T>
struct has_plus<T, std::void_t<decltype(std::declval<const T&>() + std::declval<const T&>())>> : std::true_type { };

template <class T, std::enable_if_t<has_plus<T>::value, int> = 0>
auto sum(const T& v1, const T& v2)
{
    return v1 + v2;
}

} // namespace V2




// C++ 20 (используя концепты)
namespace V3 {

template<typename T>
concept addable = requires(const T& a, const T& b)
{
    // Проверка на operator+
    a + b;
};

template <addable T>
auto sum(const T& v1, const T& v2)
{
    return v1 + v2;
}

} // namespace V3

// Тестовые структуры
struct foo3
{
    int a = 2;

    friend foo3 operator+(const foo3& f1, const foo3& f2);
};

inline foo3 operator+(const foo3& f1, const foo3& f2)
{
    foo3 f3;
    f3.a = f1.a + f2.a;

    return f3;
}

struct foo4
{
    int a = 2;
};

void test()
{
    {
        foo3 a;
        foo3 b;
        foo3 c = V1::sum(a, b);
        foo3 d = V2::sum(a, b);
        foo3 e = V3::sum(a, b);
    }

    {
        foo4 a;
        foo4 b;
        //foo4 c = V1::sum(a, b);
        //foo4 d = V2::sum(a, b);
        //foo4 e = V3::sum(a, b);
    }
}

} // namespace Example2
