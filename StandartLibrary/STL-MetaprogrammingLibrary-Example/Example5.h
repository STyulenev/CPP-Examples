#pragma once

#include <type_traits>
#include <iostream>

/*
 * =======================================================================================================================================================================
 *                                                             Type traits: Property queries
 * =======================================================================================================================================================================
 * Функции:
 * - alignment_of
 * - rank
 * - extent
 */

namespace Example5 {

namespace PQ1 { // ------------------------------------ Проверка на выравнивание (alignment_of)

struct Base1 { // 4
    int    a;
};

struct Base2 { // 8
    bool   a;
    int    b;
    double c;

};

struct Base3 { // 4
    bool   a;
    int    b;
};

// Выравнивание на 4

template <class T, class = void>
struct is_equal : std::false_type {};

template <class T>
struct is_equal<T, std::enable_if_t<std::alignment_of<T>::value == 4>> : std::true_type {};

template <typename T, std::enable_if_t<is_equal<T>::value, bool> = true >
void foo(T arg)
{}

void test()
{
    std::cout << std::alignment_of<Base1>::value << std::endl;
    std::cout << std::alignment_of<Base2>::value << std::endl;
    std::cout << std::alignment_of<Base3>::value << std::endl;

    Base1 b1;
    Base2 b2;
    Base3 b3;

    foo(b1);     // Ок, 4
    //foo(b2);   // Ошибка, 8
    foo(b3);     // Ок, 4
    foo(5);      // Ок, 4
    //foo(true); // Ошибка, 1
}

} // namespace PQ1

} // namespace Example5
